#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "i2c_helpers.h"
#include "i2c_tools.h"

extern int appCliPrintf(__const char *__restrict __format, ...);

static struct i2c_client tmp_client = {
    .adapter = NULL,
    .addr = 0x50,
};

static int i2c_bus = 0;

/******************************************************************************
 * Sub commands
******************************************************************************/

#if 0
static char i2c_help_text[] =
    "bus [muxtype:muxaddr:muxchannel] - show I2C bus info\n"
    "i2c " /* That's the prefix for the crc32 command below. */
    "crc32 chip address[.0, .1, .2] count - compute CRC32 checksum\n"
    "i2c dev [dev] - show or set current I2C bus\n"
    "i2c edid chip - print EDID configuration information\n"
    "i2c loop chip address[.0, .1, .2] [# of objects] - looping read of device\n"
    "i2c md chip address[.0, .1, .2] [# of objects] - read from I2C device\n"
    "i2c mm chip address[.0, .1, .2] - write to I2C device (auto-incrementing)\n"
    "i2c mw chip address[.0, .1, .2] value [count] - write to I2C device (fill)\n"
    "i2c nm chip address[.0, .1, .2] - write to I2C device (constant address)\n"
    "i2c probe [address] - test for and show device(s) on the I2C bus\n"
    "i2c read chip address[.0, .1, .2] length memaddress - read to memory\n"
    "i2c write memaddress chip address[.0, .1, .2] length [-s] - write memory\n"
    "          to I2C; the -s option selects bulk write in a single transaction\n"
    "i2c flags chip [flags] - set or get chip flags\n"
    "i2c olen chip [offset_length] - set or get chip offset length\n"
    "i2c reset - re-init the I2C Controller\n"
    "i2c sdram chip - print SDRAM configuration information\n"
    "i2c speed [speed] - show or set I2C bus speed";
#endif

static char i2c_help_text[] =
    "i2c bus [bus] - show or set current I2C bus\n"
    "i2c dev [dev] - show or set current I2C address\n"
    "i2c tx addr [data...] - send array of bytes to given I2C address\n"
    "i2c rx addr len - receive array of bytes from given I2C address\n"
    "i2c set reg val - set i2c chip register values\n"
    "i2c get reg [reg_size] - get i2c chip register values (reg_size = 1..4)\n"
    "i2c dump [addr_size] [reg_size] [start] [end] - dump chip registers\n"
    "i2c probe [address] [address] - test for and show device(s) on the I2C bus\n"
    "i2c detect [address] [address] - alias for `i2c probe`\n"
    ;

static int32_t i2c_tools_help(int argc, char *argv[])
{
    appCliPrintf("i2c command usage:\n%s\n", i2c_help_text);

    return 0;
}

static int32_t i2c_tools_bus(int argc, char *argv[])
{
    int bus;

    /* set */
    if (argc > 0) {
        bus = atoi(argv[0]);
        tmp_client.adapter = i2c_get_handle(bus);
        if (tmp_client.adapter) {
            appCliPrintf("i2c%d opened\n", bus);
            i2c_bus = bus;
        } else {
            appCliPrintf("Failed to open i2c%d\n", bus);
        }
    } else {
        if (tmp_client.adapter) {
            appCliPrintf("i2c%d is selected\n", i2c_bus);
        } else {
            appCliPrintf("No i2c bus selected\n");
        }
    }

    return 0;
}

static int32_t i2c_tools_dev(int argc, char *argv[])
{
    int dev;

    /* set */
    if (argc > 0) {
        dev = (int)strtol(argv[0], NULL, 16);
        if ((dev > 0) && (dev < 0xff)) {
            appCliPrintf("Dev 0x%02x selected\n", dev);
            tmp_client.addr = dev;
        } else {
            appCliPrintf("Incorrect device address 0x%x\n", dev);
        }
    } else {
        appCliPrintf("i2c device 0x%02x is selected\n", tmp_client.addr);
    }

    return 0;
}

static int32_t i2c_tools_tx(int argc, char *argv[])
{
    int i;
    uint8_t addr;
    uint8_t tx[16];
    struct i2c_client client;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }

    client.adapter = tmp_client.adapter;

    if (argc < 1) {
        appCliPrintf("No addr!\n");
        return -1;
    }

    if (argc - 1 > 16) {
        appCliPrintf("Too much data!\n");
        return -1;
    }

    addr = strtol(argv[0], NULL, 16);
    client.addr = addr;

    for (i = 0; i < argc - 1; i++) {
        tx[i] = strtol(argv[i + 1], NULL, 16);
    }

    appCliPrintf("Sending %d bytes to i2c%d 0x%02x\n",
        argc - 1, client.addr, i2c_bus);

    return i2c_tx_array(&client, tx, argc - 1);
}

static int32_t i2c_tools_rx(int argc, char *argv[])
{
    int i;
    int res;
    uint8_t len;
    uint8_t addr;
    uint8_t rx[16];
    struct i2c_client client;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }

    client.adapter = tmp_client.adapter;

    if (argc < 2) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    addr = strtol(argv[0], NULL, 16);
    len = strtol(argv[1], NULL, 10);
    client.addr = addr;

    if (len > 16) {
        appCliPrintf("Too much data!\n");
        return -1;
    }

    res = i2c_rx_array(&client, rx, len);
    if (res) {
        appCliPrintf("i2c read error %d!\n", res);
        return -1;
    }

    appCliPrintf("Received %d bytes i2c%d 0x%02x:\n",
        len, i2c_bus, client.addr);

    for (i = 0; i < len; i++) {
        appCliPrintf("%02x ", rx[i]);
    }

    appCliPrintf("\n");

    return 0;
}

static int32_t i2c_tools_probe(int argc, char *argv[])
{
    int i, j;
    int first = 0x03, last = 0x77;
    struct i2c_client client;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }
    client.adapter = tmp_client.adapter;

    if (argc > 0) {
        first = last = strtol(argv[0], NULL, 16);
    }
    if (argc > 1) {
        last = strtol(argv[1], NULL, 16);
    }

    if ((first < 0x03) || (last > 0x77)) {
        appCliPrintf("Invalid address range 0x%02x..0x%02x\n",
            first, last);
        return -1;
    }

    appCliPrintf("Probing devices on i2c%d\n", i2c_bus);

    appCliPrintf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
    for (i = 0; i < 128; i += 16) {
        appCliPrintf("%02x: ", i);
        for(j = 0; j < 16; j++) {
            int res;
            uint8_t rx[1];
            client.addr = i + j;

            /* Skip unwanted addresses */
            if ((client.addr < first) || (client.addr > last)) {
                appCliPrintf("   ");
                continue;
            }

            //res = I2C_control(handle, I2C_CMD_PROBE, &addr);
            res = i2c_rx_array(&client, rx, 1);

            if (res < 0)
                appCliPrintf("-- ");
            else
                appCliPrintf("%02x ", i+j);
        }
        appCliPrintf("\n");
    }

    return 0;
}

static int32_t i2c_tools_set(int argc, char *argv[])
{
    int32_t ret;
    uint32_t reg, val;
    int32_t reg_len, val_len;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }

    if (argc != 2) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    reg_len = hex2int_ext(argv[0], &reg);
    if (reg_len < 0) {
        appCliPrintf("Failed to parse register!\n");
        return reg_len;
    }

    val_len = hex2int_ext(argv[1], &val);
    if (val_len < 0) {
        appCliPrintf("Failed to parse value!\n");
        return val_len;
    }

    appCliPrintf("Writing i2c%d addr 0x%02x, register 0x%x (%d bytes) value 0x%x (%d bytes)\n",
        i2c_bus, tmp_client.addr, reg, reg_len, val, val_len);

    ret = i2c_set_reg(&tmp_client,
        reg, reg_len, val, val_len);

    if (ret) {
        appCliPrintf("Failed %d\n", ret);
    }

    return ret;
}

static int32_t i2c_tools_get(int argc, char *argv[])
{
    int32_t ret;
    uint32_t reg, val = 0;
    int32_t reg_len, val_len = 1;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }

    if (argc < 1) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    reg_len = hex2int_ext(argv[0], &reg);
    if (reg_len < 0) {
        appCliPrintf("Failed to parse register!\n");
        return reg_len;
    }

    if (argc >= 2) {
        val_len = atoi(argv[1]);
        if ((val_len < 0) || (val_len > 4)) {
            appCliPrintf("Invalid register len!\n");
            return -1;
        }
    }

    appCliPrintf("Reading  i2c%d addr 0x%02x, register 0x%x (%d bytes): (%d bytes)\n",
        i2c_bus, tmp_client.addr, reg, reg_len, val_len);

    ret = i2c_get_reg(&tmp_client,
        reg, reg_len, &val, val_len);

    if (ret) {
        appCliPrintf("Read failed %d\n", ret);
    } else {
        appCliPrintf("value 0x%x\n", val);
    }

    return ret;
}

static int32_t i2c_tools_dump(int argc, char *argv[])
{
    int i, j;
    uint32_t reg_len = 1, val_len = 1;
    uint32_t first = 0x00, last = 0xff;

    if (tmp_client.adapter == NULL) {
        appCliPrintf("No i2c bus selected!\n");
        return -1;
    }

    if (argc > 0) {
        reg_len = atoi(argv[0]);
        if (reg_len > 4) {
            appCliPrintf("Invalid addressing len!\n");
            return -1;
        }
    }

    if (argc > 1) {
        val_len = atoi(argv[1]);
        if (val_len > 4) {
            appCliPrintf("Invalid register len!\n");
            return -1;
        }
    }

    if (argc > 2) {
        first = last = strtol(argv[2], NULL, 16);
    }
    if (argc > 3) {
        last = strtol(argv[3], NULL, 16);
    }

    if (first > last) {
        appCliPrintf("Invalid register address range 0x%x..0x%x\n",
            first, last);
        return -1;
    }

    appCliPrintf("Dumping i2c%d device 0x%02x (addr size %d, reg size %d)\n",
        i2c_bus, tmp_client.addr, reg_len, val_len);

    /* TODO: fix for addresign and register sizes != byte */
    appCliPrintf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
    for (i = (first & (~0x0f)); i < ((last + 15) & (~0x0f)); i += 16) {
        appCliPrintf("%02x: ", i);
        for(j = 0; j < 16; j++) {
            int32_t res;
            uint32_t val = 0;
            uint32_t reg = i + j;

            /* Skip unwanted regs */
            if (reg < first || reg > last) {
                appCliPrintf("   ");
                continue;
            }

            res = i2c_get_reg(&tmp_client,
                reg, reg_len, &val, val_len);

            if (res < 0)
                appCliPrintf("xx ");
            else
                appCliPrintf("%02x ", val);
        }
        appCliPrintf("\n");
    }

    return 0;
}

struct i2c_command_desc {
    const char *cmd;
    int32_t (*execute)(int argc, char *argv[]);
};

static const struct i2c_command_desc commands[] = {
    {"probe", &i2c_tools_probe},
    {"detect", &i2c_tools_probe},
    {"set", &i2c_tools_set},
    {"get", &i2c_tools_get},
    {"dump", &i2c_tools_dump},
    {"tx", &i2c_tools_tx},
    {"rx", &i2c_tools_rx},
    {"bus", &i2c_tools_bus},
    {"dev", &i2c_tools_dev},
    {"help", &i2c_tools_help},
    {NULL, NULL},
};

int32_t i2c_tools(int argc, char *argv[])
{
    /* first arg is "i2c" */
    argc--;
    argv++;

    const struct i2c_command_desc *desc;
    for (desc = &commands[0]; desc->cmd != NULL; desc++)
    {
        if (strcmp(argv[0], desc->cmd) == 0)
        {
            return desc->execute(argc - 1, argv + 1);
        }
    }

    if (desc->cmd == NULL)
    {
        appCliPrintf("Unknown i2c command\n");
    }

    return -1;

#if 0
    FILE *src=NULL, *dst=NULL;
    uint32_t bytesWrite = 0;
    uint32_t bytesRead = 0;
    uint32_t done = 0;
    int32_t retStat = 0;
    size_t bufSize = FS_APP_PATH_BUF_SIZE;
    size_t fileSize;

    strcpy(gFsInFileName, "test_rd.txt");
    /* Open the file for reading. */
    src = fopen(gFsInFileName, "rb");
    /* If there was some problem opening the file, then return an error. */
    if(src == NULL)
    {
        appCliPrintf("Failed to open file %s for read !!!\n", gFsInFileName);
        retStat = -1;
    }

    if(retStat == 0)
    {
        fseek(src, 0, SEEK_END);
        fileSize = ftell(src);

        appCliPrintf("Opened %s file of size %d bytes for reading !!!\n", gFsInFileName, fileSize);
    }

    strcpy(gFsOutFileName, "test_wr.txt");
    dst = fopen(gFsOutFileName, "wb");
    if(dst == NULL)
    {
        appCliPrintf("Failed to open file %s for write !!!\n", gFsOutFileName);
        retStat = -1;
    }

    if(retStat == 0)
    {
        appCliPrintf("Opened %s file for writing !!!\n", gFsOutFileName, fileSize);

        /*
         * Enter a loop to repeatedly read data from the file and copy to destination file,
         * until the end of the file is reached.
         */
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in
             * temporary buffer, including a space for the trailing null.
             */
            bytesRead = fread(gFsAppDataBuf, 1, bufSize, src);

            /*
             * If there was an error reading, then print a newline and return
             * error to the user.
             */
            if(bytesRead != bufSize)
            {
                done = 1;
            }

            if(bytesRead > 0)
            {
                /*
                 * Write the data to the destination file user has selected.
                 * If there was an error writing, then print a newline and return
                 * error to the user.
                 */
                bytesWrite = fwrite(gFsAppDataBuf, 1, bytesRead, dst);
                if(bytesRead != bytesWrite)
                {
                    appCliPrintf("Fail to write into file !!!!\n");
                    done = 1;
                    retStat = -1;
                }
            }
            /*
             * Continue reading until less than the full number of bytes are
             * read. That means the end of the buffer was reached.
             */
        } while(!done);
    }

    /*
     * Close the files.
     */
    if(src!=NULL)
    {
        fclose(src);
    }
    if(dst!=NULL)
    {
        fclose(dst);
    }
    if(retStat==0)
    {
        appCliPrintf("Copied %s file of size %d bytes to file %s !!!\n",
            gFsInFileName, fileSize, gFsOutFileName);
    }
    return(retStat);
#endif
}

int i2c_tools_complete(char *line, int cursor, int n)
{
    const struct i2c_command_desc *desc;
    const struct i2c_command_desc *proposed = NULL;
    char *space = strchr(line, ' ');
    int space_pos = -1;
    int shift;
    int len = strlen(line);

    if (space != NULL)
    {
        space_pos = space - line;
    }

    if (cursor < space_pos || space_pos < 0)
    {
        for (desc = &commands[0]; desc->cmd != NULL; desc++)
        {
            if (strncmp(line, desc->cmd, cursor) == 0)
            {
                if (proposed == NULL)
                {
                    proposed = desc;
                }
                else
                {
                    /*.. several commands found, cannot decide which one to choose */
                    proposed = NULL;
                    break;
                }
            }
        }

        if (proposed != NULL)
        {
            int insert_len = strlen(proposed->cmd) - cursor;
            shift = insert_len + 1 + 1; /*.. also a space and a terminator */
            if (len + shift >= n)
            {
                shift = n - len - 1 - 2;
            }

            char *insert_at = line + cursor;

            memmove(insert_at + shift, insert_at, shift);
            strncpy(insert_at, proposed->cmd + cursor, shift - 1);
            strncpy(insert_at + insert_len, " ", 2);

            /*.. terminate anyway */
            line[n - 1] = '\0';

            cursor += shift - 1;
        }
    }

    return cursor;
}

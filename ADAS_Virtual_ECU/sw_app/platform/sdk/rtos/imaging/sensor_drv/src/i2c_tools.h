#ifndef _I2C_TOOLS_H_
#define _I2C_TOOLS_H_

/******************************************************************************
 * Priv helpers
******************************************************************************/

static int32_t hex2int_ext(char *hex, uint32_t *ret) {
    int len = 0;
    uint32_t val = 0;

    while (*hex) {
        // get current character then increment
        uint8_t byte = *hex++;

        if ((byte == 'x') && (len == 1) && (val == 0)) {
            /* skip 0x */
            len = 0;
            continue;
        }

        /* transform hex character to the 4bit equivalent number,
         * using the ascii table indexes */
        if (byte >= '0' && byte <= '9')
            byte = byte - '0';
        else if (byte >= 'a' && byte <='f')
            byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F')
            byte = byte - 'A' + 10;
        else
            /* invalid char in hex */
            return -1;
        /* shift 4 to make space for new digit, and add the 4 bits
         * of the new digit */
        val = (val << 4) | (byte & 0xF);
        len++;

        if (len == 8)
            break;
    }

    if (ret != NULL) {
        *ret = val;
    }

    /* return size in bytes */
    return ((len + 1) / 2);
}

#endif

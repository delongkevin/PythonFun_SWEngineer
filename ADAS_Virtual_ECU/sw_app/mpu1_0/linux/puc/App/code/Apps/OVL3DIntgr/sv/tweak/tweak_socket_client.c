#include "tweak_socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>


static ssize_t recv_full(int fd, void* buffer, ssize_t sz)
{
    ssize_t bytes_read = 0;

    while (bytes_read < sz)
    {
        ssize_t ret = recv(fd, buffer + bytes_read, sz - bytes_read, 0);

        if (ret > 0)
        {
            bytes_read+=ret;
        }
        else if (ret == 0)
        {
            break;
        }
        else
        {
            return ret;
        }
    }

    return bytes_read;
}


static ssize_t send_full(int fd, void* buffer, ssize_t sz)
{
    ssize_t bytes_write = 0;

    while (bytes_write < sz)
    {
        ssize_t ret = send(fd, buffer + bytes_write, sz - bytes_write, 0);

        if (ret > 0)
        {
            bytes_write+=ret;
        }
        else if (ret == 0)
        {
            break;
        }
        else
        {
            return ret;
        }
    }

    return bytes_write;
}



static RecieveStatus recv_time(int sock, void* buf, uint32_t sz, uint32_t sec)
{
    printf("recv_time\n");
    fd_set f;
    FD_ZERO(&f);
    FD_SET(sock, &f);

    struct timeval timeout = {0};
    timeout.tv_sec = sec;

    int ret = select(FD_SETSIZE, &f, 0, 0, &timeout);

    RecieveStatus status = RecieveStatus_OK;

    printf("recv_time, select return %d\n", ret);

    if (ret > 0)
    {
        status = RecieveStatus_OK;

        if (recv_full(sock, buf, sz) != sz)
        {
            status = RecieveStatus_Failed;
            ret = -1;
            printf("recv error\n");
        }
    }
    else
    {
        status = RecieveStatus_Timeout;
        printf("recv timeout\n");
    }

    return status;
}





#define CHECK_STRING(NAME) if (strlen((NAME)) >= SOCKET_STRING_SIZE)


static pthread_mutex_t socket_lock = {0};
static pthread_mutex_t update_lock = {0};
static pthread_cond_t update_cond = {0};
static pthread_t g_read_thread = 0;
static pthread_t g_update_thread = 0;
static int g_socket_to = 0;
static int g_socket_from = 0;
static bool b_first = true;
static bool ui_started = false;

extern const char* SERV_IP_ADR;

static uint32_t g_rand_port = 1;

typedef struct
{
    char str[SOCKET_STRING_SIZE];
}queue_string;

#define UPD_Q_SIZE 16

static queue_string queue_update[UPD_Q_SIZE] = {0};

tweak_socket_data_t answer = {0};

struct socket_data_t
{
    int socket;
    struct sockaddr_in newAddr;
};

static bool socket_start_server(const char* ip);

static void* tweak_update_thr(void* param)
{
    pthread_mutex_lock(&update_lock);

    while(1)
    {

        if (queue_update[0].str[0] == 0 && g_socket_from)
        {
            pthread_cond_wait(&update_cond, &update_lock);
        }

        if (g_socket_from == 0)
            break;

        if (queue_update[0].str[0] != 0)
        {
            queue_string zero = {0};
            queue_string s = queue_update[0];
            memmove(&queue_update[0], &queue_update[1], sizeof(queue_string)*(UPD_Q_SIZE - 1));
            queue_update[UPD_Q_SIZE - 1] = zero;
            pthread_mutex_unlock(&update_lock);
            tweak_on_update(s.str);
            pthread_mutex_lock(&update_lock);
        }
    }
        pthread_mutex_unlock(&update_lock);

    return NULL;
}

static void* socket_read_thread(void* cdata)
{
    tweak_socket_data_t buffer;

    while (1)
    {
        ui_started = 0;

        if (!socket_start_server(SERV_IP_ADR))
        {
            printf("failed to connect to the server: %s\n", strerror(errno));
            return NULL;
        }

        tweak_on_connect(cdata);

        int socket = g_socket_from;

        pthread_create(&g_update_thread, 0, tweak_update_thr, 0);

        while (1)
        {
            size_t bytes_count = recv_full(socket, &buffer, sizeof(buffer));

            if (bytes_count == sizeof(tweak_socket_data_t))
            {
                if (buffer.message_id == func_tweak_on_update)
                {
                    pthread_mutex_lock(&update_lock);
                    int i;
                    for (i = 0; i < UPD_Q_SIZE; i++)
                    {
                        if (queue_update[i].str[0] == 0)
                        {
                            if (i > 0 && strcmp(queue_update[i-1].str, (const char*)buffer.data) == 0)
                            {
                                break;
                            }

                            queue_string s = {0};
                            strcpy(s.str, (const char*)buffer.data);
                            queue_update[i] = s;
                            pthread_cond_signal(&update_cond);
                        }
                    }
                    pthread_mutex_unlock(&update_lock);
                }
                else if (buffer.message_id == func_tweak_echo)
                {
                    send_full(socket, &buffer, sizeof(buffer));
                }
                else
                {
                    printf("Illegal message is received\n");
                }
            }
            else
            {
                printf("Error wrong data received sz=%d\n", (int)bytes_count);
                break;
            }
        }

        pthread_mutex_lock(&update_lock);

        if (g_socket_from)
        {
            close(g_socket_from);
        }
        if (g_socket_to)
        {
            close(g_socket_to);
        }

        g_socket_from = 0;
        g_socket_to = 0;

        pthread_cond_broadcast(&update_cond);
        pthread_mutex_unlock(&update_lock);

        void* ret;
        pthread_join(g_update_thread, &ret);

        pthread_mutex_lock(&socket_lock);
        pthread_mutex_unlock(&socket_lock);

        usleep(100000);
    }

    return 0;
}

Answer get_answer()
{
    Answer ret;
    ret.ui64 = 0;

    tweak_socket_data_t t = {0};
    size_t bytes_count = recv_full(g_socket_to, &t, sizeof(t));

    if (bytes_count == sizeof(t))
    {
        Answer* p_ret = ((Answer*)t.data);
        ret = *p_ret;
    }

    return ret;
}


static void
init_sockaddr(struct sockaddr_in *name,
              const char *hostname,
              uint16_t port)
{
    struct hostent *hostinfo;

    name->sin_family = AF_INET;
    name->sin_port = htons(port);
    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL)
    {
        fprintf(stderr, "Unknown host %s.\n", hostname);
        return;
    }
    name->sin_addr = *(struct in_addr *)hostinfo->h_addr;
}


static int connect_to_server_old(const char *ip, uint32_t port)
{
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("socket (client)");
        return -1;
    }

    /* Connect to the server. */
    struct sockaddr_in servername = {0};

    init_sockaddr(&servername, ip, port);
    if (0 > connect(sock,
                    (struct sockaddr *)&servername,
                    sizeof(servername)))
    {
        printf("connect (client)");
        return -1;
    }

    return sock;
}

#include <fcntl.h>

static int connect_to_server(const char *ip, uint32_t port)
{
    int res;
    long arg;
    fd_set myset;
    struct timeval tv;
    int valopt;
    socklen_t lon;

    // Create socket
    int soc = socket(AF_INET, SOCK_STREAM, 0);
    if (soc < 0)
    {
        fprintf(stderr, "Error creating socket (%d %s)\n", errno, strerror(errno));
        return -1;
    }

    struct sockaddr_in servername = {0};
    init_sockaddr(&servername, ip, port);

    // Set non-blocking
    if ((arg = fcntl(soc, F_GETFL, NULL)) < 0)
    {
        fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
        close(soc);
        return -1;
    }
    arg |= O_NONBLOCK;
    if (fcntl(soc, F_SETFL, arg) < 0)
    {
        fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
        close(soc);
        return -1;
    }

    // Trying to connect with timeout
    res = connect(soc, (struct sockaddr *)&servername, sizeof(servername));
    if (res < 0)
    {
        if (errno == EINPROGRESS)
        {
            do
            {
                tv.tv_sec = 0;
                tv.tv_usec = 400000;
                FD_ZERO(&myset);
                FD_SET(soc, &myset);
                res = select(soc + 1, NULL, &myset, NULL, &tv);

                if (res < 0 && errno != EINTR)
                {
                    //fprintf(stderr, "Error connecting %d - %s\n", errno, strerror(errno));
                    break;
                }
                else if (res > 0)
                {
                    // Socket selected for write
                    lon = sizeof(int);
                    if (getsockopt(soc, SOL_SOCKET, SO_ERROR, (void *)(&valopt), &lon) < 0)
                    {
                        //fprintf(stderr, "Error in getsockopt() %d - %s\n", errno, strerror(errno));
                        res = -1;
                        break;
                    }
                    // Check the value returned...
                    if (valopt)
                    {
                        //fprintf(stderr, "Error in delayed connection() %d - %s\n", valopt, strerror(valopt));
                        res = -1;
                        break;
                    }
                    break;
                }
                else
                {
                    //fprintf(stderr, "Timeout in select() - Cancelling!\n");
                    res = -1;
                    break;
                }
            } while (1);
        }
        else
        {
            res = -1;
        }
    }
    // Set to blocking mode again...
    if ((arg = fcntl(soc, F_GETFL, NULL)) < 0)
    {
        fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
    }
    arg &= (~O_NONBLOCK);
    if (fcntl(soc, F_SETFL, arg) < 0)
    {
        fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
    }

    if (res < 0)
    {
        close(soc);
        soc = -1;
    }

    return soc;
}

static bool socket_start_server(const char* ip)
{
    int i;
    int sock = -1;

    if (!ui_started)
    {
        while (1)
        {
            //printf("connecting to the server...%s, %d\n", ip, PORT);

            sock = connect_to_server(ip, PORT);
            if (sock < 0)
            {
                //printf("cannot connect to server, try again...\n");
                usleep(32000);
                continue;
            }

            tweak_socket_data_t estab = {0};
            estab.message_id = func_tweak_estab;
            estab.data[0] = g_rand_port;

            if (send(sock, &estab, sizeof(estab), 0) != sizeof(estab))
            {
                printf("connecting to the server, sening error...\n");
                close(sock);
                sock = -1;
                continue;
            }

            {
                tweak_socket_data_t b = {0};
                bool ret_recv = recv_time(sock, &b, sizeof(b), 1) == 0;

                if (!ret_recv || b.message_id != func_tweak_resp)
                {
                    close(sock);
                    sock = -1;
                    continue;
                }

                b.message_id = func_tweak_estab2;
                send(sock, &b, sizeof(estab), 0);
            }


            close(sock);
            break;
        }

        if (sock < 0)
        {
            return false;
        }
    }

    ui_started = true;

    sock = -1;
    for (i = 0; i < 16; i++)
    {
        sock = connect_to_server_old(ip, PORT + g_rand_port);
        if (sock < 0)
        {
            //printf("cannot connect to UI server, try again...\n");
            usleep(1000000);
            continue;
        }
        g_socket_to = sock;
        break;
    }

    if (sock < 0)
        return false;

    sock = -1;
    for (i = 0; i < 16; i++)
    {
        sock = connect_to_server_old(ip, PORT + g_rand_port + 1);
        if (sock < 0)
        {
            //printf("cannot connect to UI server, try again...\n");
            usleep(1000000);
            continue;
        }
        g_socket_from = sock;
        break;
    }

    if (sock < 0)
    {
        close(g_socket_to);
        return false;
    }

    //pthread_create(&g_read_thread, 0, socket_read_thread, 0);

    return true;
}

int tweak_connect(void *cdata)
{
    if (b_first)
    {
        pthread_mutex_init(&socket_lock, 0);
        pthread_mutex_init(&update_lock, 0);
        pthread_cond_init(&update_cond, 0);
        b_first = false;

        g_rand_port = ((clock() & 31) + 1)*2;
    }

    if (g_read_thread == 0)
    {
        pthread_create(&g_read_thread, 0, socket_read_thread, cdata);
#if 0
        if (!socket_start_server(SERV_IP_ADR))
        {
            return -1;
        }
#endif
    }

    //printf("TCP/IP tweak tool: connection is established\n");

    return 0;
}

void tweak_add_widget(const char* name)
{
    CHECK_STRING(name) return;
    if (b_first)
    {
        pthread_mutex_init(&socket_lock, 0);
        pthread_mutex_init(&update_lock, 0);
        pthread_cond_init(&update_cond, 0);
        b_first = false;

        g_rand_port = ((clock() & 31) + 1)*2;
    }

    if (g_read_thread == 0)
    {
        if (!socket_start_server(SERV_IP_ADR))
        {
            return;
        }
    }

    pthread_mutex_lock(&socket_lock);
    tweak_add_widget_t d = {0};
    strcpy(d.name, name);

    tweak_socket_data_t to_send = {0};
    to_send.message_id = func_tweak_add_widget;
    memcpy(to_send.data, &d, sizeof(tweak_add_widget_t));

    send(g_socket_to, &to_send, sizeof(to_send), 0);
    get_answer();
    pthread_mutex_unlock(&socket_lock);
}

void tweak_add_layout(unsigned int width, unsigned int horizontal_vertical, const char* name)
{
    CHECK_STRING(name) return;
    if (b_first)
    {
        tweak_add_widget(name);
    }

    pthread_mutex_lock(&socket_lock);

    if (g_read_thread && g_socket_to)
    {
        tweak_add_layout_t d = {0};

        d.width = width;
        d.horizontal_vertical = horizontal_vertical;
        strcpy(d.name, name);

        tweak_socket_data_t to_send = {0};
        to_send.message_id = func_tweak_add_layout;
        memcpy(to_send.data, &d, sizeof(tweak_add_layout_t));

        send(g_socket_to, &to_send, sizeof(to_send), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);

}

void tweak_close()
{
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_close;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}

uint64_t tweak_fopen(const char* name, const char* mode)
{
    CHECK_STRING(name) return 0;
    tweak_fopen_t buf = {0};
    strncpy(buf.name, name, sizeof(buf.name) - 1);
    strncpy(buf.mode, mode, sizeof(buf.mode) - 1);
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_fopen;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_fclose(uint64_t fd)
{
    tweak_fclose_t buf = {0};
    buf.fd = fd;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_fclose;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_ftell(uint64_t fd)
{
    tweak_fclose_t buf = {0};
    buf.fd = fd;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_ftell;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}


uint64_t tweak_fseek(uint64_t fd, int32_t offset, int32_t where)
{
    tweak_fseek_t buf = {0};
    buf.fd = fd;
    buf.offset = offset;
    buf.where = where;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_fseek;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}


uint64_t tweak_fwrite(uint64_t fd, uint32_t sz, void* p_data)
{
    tweak_fwrite_t buf = {0};
    buf.fd = fd;
    buf.sz = sz;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_fwrite;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        send_full(g_socket_to, p_data, sz);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint32_t tweak_json_config_write(void* p_data, uint32_t max_sz, int cfg_enum, const char* cfg_name_ver, const char* path)
{
    tweak_json_config_read_t buf = {0};
    buf.cfg_enum = cfg_enum;
    strcpy(buf.cfg_name_ver, cfg_name_ver);
    buf.max_sz = max_sz;
    strcpy(buf.path, path);

    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_json_config_write;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        send_full(g_socket_to, p_data, max_sz);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}


uint32_t tweak_json_config_read(void* p_data, uint32_t max_sz, int cfg_enum, const char* cfg_name_ver, const char* path)
{
    tweak_json_config_read_t buf = {0};
    buf.cfg_enum = cfg_enum;
    strcpy(buf.cfg_name_ver, cfg_name_ver);
    buf.max_sz = max_sz;
    strcpy(buf.path, path);

    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_json_config_read;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        ssize_t recv_sz = recv_full(g_socket_to, p_data, max_sz);
        res = get_answer().ui64;

        if (recv_sz != max_sz)
        {
            res = 0;
        }
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_fread(uint64_t fd, uint32_t sz, void* p_data)
{
    tweak_fread_t buf = {0};
    buf.fd = fd;
    buf.sz = sz;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_fread;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        ssize_t recv_sz = recv_full(g_socket_to, p_data, sz);
        res = get_answer().ui64;

        if (recv_sz != sz)
        {
            res = 0;
        }
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_config_fopen(const char* name, const char* mode)
{
    CHECK_STRING(name) return 0;
    tweak_fopen_t buf = {0};
    strncpy(buf.name, name, sizeof(buf.name) - 1);
    strncpy(buf.mode, mode, sizeof(buf.mode) - 1);
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_config_fopen;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_config_fclose(uint64_t fd)
{
    tweak_fclose_t buf = {0};
    buf.fd = fd;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_config_fclose;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

uint64_t tweak_config_add(uint32_t sz, void* p_data)
{
    tweak_fwrite_t buf = {0};
    buf.sz = sz;
    pthread_mutex_lock(&socket_lock);

    uint64_t res = 0;

    if (g_read_thread && g_socket_to)
    {
        tweak_socket_data_t data = {0};
        data.message_id = func_tweak_config_add;
        memcpy(&data.data[0], &buf, sizeof(buf));
        send(g_socket_to, &data, sizeof(data), 0);
        send_full(g_socket_to, p_data, sz);
        res = get_answer().ui64;
    }
    pthread_mutex_unlock(&socket_lock);

    return res;
}

void tweak_get_file_path(char* dst, const char* mask, uint32_t read)
{
    CHECK_STRING(mask) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_get_file_path_t p = {0};
        strcpy(p.mask, mask);
        p.read = read;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_get_file_path;
        send(g_socket_to, &data, sizeof(data), 0);

        char buf[SOCKET_STRING_SIZE] = {0};
        recv_full(g_socket_to, buf, SOCKET_STRING_SIZE);
        strcpy(dst, buf);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}


void tweak_add_slider(const char* name, double minv, double maxv, double def, unsigned int precision)
{
    CHECK_STRING(name) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_add_slider_t p = {0};
        strcpy(p.name, name);
        p.minv = minv;
        p.maxv = maxv;
        p.def = def;
        p.precision = precision;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_add_slider;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();

    }
    pthread_mutex_unlock(&socket_lock);
}

void tweak_add_spinbox(const char* name, double minv, double maxv, double def, unsigned int precision)
{
    CHECK_STRING(name) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_add_slider_t p = {0};
        strcpy(p.name, name);
        p.minv = minv;
        p.maxv = maxv;
        p.def = def;
        p.precision = precision;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_add_spinbox;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}

void tweak_add_checkbox(const char* name, int def_val)
{
    CHECK_STRING(name) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_add_checkbox_t p = {0};
        strcpy(p.name, name);
        p.def_val = def_val;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_add_checkbox;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}

void tweak_add_button(const char* name)
{
    CHECK_STRING(name) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_add_checkbox_t p = {0};
        strcpy(p.name, name);
        p.def_val = 0;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_add_button;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}

void tweak_add_groupbox(const char* name, const char* desc, unsigned int def)
{
    if (strlen((name)) >= SOCKET_STRING_SIZE_GRBOX_NAME) return;
    if (strlen((desc)) >= SOCKET_STRING_SIZE_GRBOX_DESC) return;

    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_add_groupbox_t p = {0};
        strcpy(p.name, name);
        strcpy(p.desc, desc);
        p.def_value = def;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_add_groupbox;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}

double tweak_get(const char* name, double defval)
{
    CHECK_STRING(name) return defval;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_get_t p = {0};
        strcpy(p.name, name);
        p.defval = defval;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_get;
        send(g_socket_to, &data, sizeof(data), 0);
        defval = get_answer().f64;
    }
    pthread_mutex_unlock(&socket_lock);
    return defval;
}

void tweak_set(const char* name, double val)
{
    CHECK_STRING(name) return;
    pthread_mutex_lock(&socket_lock);
    if (g_read_thread && g_socket_to)
    {
        tweak_get_t p = {0};
        strcpy(p.name, name);
        p.defval = val;

        tweak_socket_data_t data = {0};
        memcpy(data.data, &p, sizeof(p));
        data.message_id = func_tweak_set;
        send(g_socket_to, &data, sizeof(data), 0);
        get_answer();
    }
    pthread_mutex_unlock(&socket_lock);
}



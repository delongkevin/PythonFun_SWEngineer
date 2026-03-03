#ifndef READLINE_H
#define READLINE_H

#ifdef __cplusplus
extern "C"
{
#endif

#define TERMINAL_WIDTH   80     ///< Terminal width in chars

// History buffer holding zero terminated lines
//
struct rl_history {
    char buf[1024];
    int  len;       ///< First free byte in the buffer
    int  lines;     ///< Number of lines in the history
};

int  readline(const char *prompt, char *s, int n, struct rl_history *h);

#ifdef __cplusplus
}
#endif

#endif /* READLINE_H */

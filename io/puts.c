#include <internal/syscall.h>
#include <string.h>
#include <errno.h>

int puts(const char *str) {
    int ret = syscall(__NR_write, 1, str, strlen(str));

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    int newline_ret = syscall(__NR_write, 1, "\n", 1);

    if (newline_ret < 0) {
        errno = -newline_ret;
        return -1;
    }

    return ret + 1;
}

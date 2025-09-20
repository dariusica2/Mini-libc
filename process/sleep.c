#include <internal/types.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec t;

    t.tv_sec = seconds;
    t.tv_nsec = 0;

	return nanosleep(&t, NULL);
}

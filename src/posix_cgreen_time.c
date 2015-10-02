#include "cgreen/internal/cgreen_time.h"
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#if defined(__FreeBSD__) || defined(__linux__) || defined(__APPLE__)
#  include <sys/time.h>
#  define HAVE_GETTIMEOFDAY 1
#else
#  error "Your POSIX platform does not support gettimeofday(). Please report a bug to http://github.com/cgreen-devs/cgreen/issues"
#endif

#ifdef __cplusplus
namespace cgreen {
#endif

#if defined(HAVE_GETTIMEOFDAY)
uint32_t cgreen_time_get_current_milliseconds() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) != 0) {
        fprintf(stderr, "cgreen error: could not get time of day\n");
        return 0;
    }

    return tv.tv_sec * 1000u + tv.tv_usec / 1000u;
}
#endif

#ifdef __cplusplus
} // namespace cgreen
#endif

/* vim: set ts=4 sw=4 et cindent: */

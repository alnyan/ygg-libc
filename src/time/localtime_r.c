#include <time.h>

struct tm *localtime_r(const time_t *time_ptr, struct tm *ret) {
	struct tm tm;
	if (!gmtime_r(time_ptr, &tm)) {
        return NULL;
    }
	*ret = tm;
	return ret;
}

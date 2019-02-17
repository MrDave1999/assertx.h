#ifndef _INC_ASSERTX
#define _INC_ASSERTX

#include <stdio.h>

#ifndef CHANGE_VALUE_RETURN
	#define CHANGE_VALUE_RETURN (0)
#endif

#define assertr(condition, ...) \
if(!!!(!(!(condition)))) \
{ \
	printf(__VA_ARGS__);\
	printf("\n"); \
	return CHANGE_VALUE_RETURN; \
}

#define assertc(condition, ...) \
if(!!!(!(!(condition)))) \
{ \
	printf(__VA_ARGS__);\
	printf("\n"); \
	continue; \
}

#endif /* _INC_ASSERTX */

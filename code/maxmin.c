#include <stdio.h>

#define UCHAR_MAX      ((unsigned char)(~0U))
#define CHAR_MAX       ((char)(UCHAR_MAX >> 1))
#define CHAR_MIN       (-CHAR_MAX - 1)

///*
 #define CHAR_SHIFT      (sizeof(long long) << 3 + 1)
 #define UUCHAR_MAX      ((unsigned char)((1 << CHAR_SHIFT) - 1))
//*/

#define clamp(val, min, max) ({			\
	typeof(val) __val = (val);		\
	typeof(min) __min = (min);		\
	typeof(max) __max = (max);		\
	(void) (&__val == &__min);		\
	(void) (&__val == &__max);		\
	__val = __val < __min ? __min: __val;	\
	__val > __max ? __max: __val; })

#define max(x, y) ({				\
	typeof(x) _max1 = (x);			\
	typeof(y) _max2 = (y);			\
	(void) (&_max1 == &_max2);		\
	_max1 > _max2 ? _max1 : _max2; })
	
int main()
{
	printf("UUCHAR_MAX:\t%x\n", UUCHAR_MAX);
	printf("CHAR_MAX:\t%d\n", CHAR_MAX);
	printf("CHAR_MIN:\t%d\n", CHAR_MIN);

	return 0;
}

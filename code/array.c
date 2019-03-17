#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUILD_BUG_ON(e) 				((void)sizeof(char[1 - 2*!!(e)]))
#define BUILD_BUG_ON_ZERO(e) 		(sizeof(char[1 - 2 * !!(e)]) - 1)

#define __must_be_array(a) \
  BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))

#define IS_ARRAY_PTR(p)	(!__builtin_types_compatible_p(typeof(p), typeof(&p[0])))
	
int main()
{
  char p[10][20];
  int *a = 0;
  
  printf("IS_ARRAY_PTR:%d, ARRAY_SIZE:%d\n", IS_ARRAY_PTR(p), ARRAY_SIZE(p));
  printf("IS_ARRAY_PTR:%d\n", IS_ARRAY_PTR(a));
  
  printf("BUILD_BUG_ON_ZERO(0):%d\n", BUILD_BUG_ON_ZERO(1));
  printf("BUILD_BUG_ON(0):%d\n", BUILD_BUG_ON(0));
  
  return 0;
}

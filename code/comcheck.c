#include <stdio.h>
#include <stdlib.h>

#define BUILD_BUG_ON(e) 				((void)sizeof(char[1 - 2*!!(e)]))
#define BUILD_BUG_ON_ZERO(e) 		(sizeof(char[1 - 2 * !!(e)]) - 1)
#define __must_be_array(a) \
  BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))

struct map
{
	int used[2];		/* 8 */
	int empty[5];		/* 20 */	
	
	char pad[32 - 28];
} men = {{1, 2}, {0, 3, 4, 5, 6}};

int main()
{
	BUILD_BUG_ON(sizeof(men) != 32);
  printf("BUILD_BUG_ON_ZERO(0):%d, %d\n", BUILD_BUG_ON_ZERO(0), sizeof(men));
	
  return 0;
}

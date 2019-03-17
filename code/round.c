#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* printtime - display the difference between
 * two timestamps in sec, usec */
void printtime(struct timeval * start, struct timeval * end)
{
    unsigned long long diff_us;

    diff_us =
        (((unsigned long long)end->tv_sec)*1000000 + end->tv_usec) -
        (((unsigned long long)start->tv_sec)*1000000 + start->tv_usec);

    printf("%llu s, %06llu us\n", diff_us/1000000, diff_us%1000000);
}

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define roundup(x, y) ((((x) + ((y) - 1)) / (y)) * (y))
#define roundup1(x, y) ((x)%(y) ? ((x)/(y) + 1) * (y) : x)
	
int main()
{
	unsigned i = 0, j = 0;
  struct timeval start, end;
  gettimeofday(&start, NULL);
	for(i = 0; i < 900000; i++)
		j = roundup(i, 3);
  gettimeofday(&end, NULL);
  printtime(&start, &end);
	
  gettimeofday(&start, NULL);
	for(i = 0, j = 0; i < 900000; i++)
		j = roundup1(i, 3);
  gettimeofday(&end, NULL);
  printtime(&start, &end);
  return 0;
}

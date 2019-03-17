#include <stdio.h>

/*
 * Determine the real variable name from the name visible in the
 * kernel sources.
 */
#define per_cpu_var(var) per_cpu__##var
#define per_cpu(var, cpu)			(*((void)(cpu), &per_cpu_var(var)))
#define __get_cpu_var(var)			per_cpu_var(var)
#define __raw_get_cpu_var(var)			per_cpu_var(var)

int main()
{
  void *rdp = &per_cpu(rcu_data, 0);
	return 0;
}

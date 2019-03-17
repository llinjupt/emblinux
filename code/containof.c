#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct man
{
	char name[32];
	unsigned int id;	
	unsigned char age;
	char address[64];
}man_t;

int main()
{
	man_t tom = {"Tom", 0, 24, "ShangHai China"};
	man_t *man = NULL;
	
	printf("tom:%p, tom.age:%p, offsetof(man_t, age): %d\n", 
					&tom, &tom.age, offsetof(man_t, age));
					
	man = container_of(&tom.age, man_t, age);
	printf("tom.name:%s, tom.id:%d, tom.age:%u, tom.address:%s\n", 
					man->name, man->id, man->age, man->address);
	
	return 0;
}

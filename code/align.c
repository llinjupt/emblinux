#include <stdio.h>
enum system_states {
        SYSTEM_BOOTING,
        SYSTEM_RUNNING,
        SYSTEM_HALT,
        SYSTEM_POWER_OFF,
        SYSTEM_RESTART,
        SYSTEM_SUSPEND_DISK,
} system_state;

#define ALIGN(x, a)              __ALIGN_MASK(x, (typeof(x))(a) - 1)
#define __ALIGN_MASK(x, mask)    (((x) + (mask))&~(mask))
#define PTR_ALIGN(p, a)         ((typeof(p))ALIGN((unsigned long)(p), (a)))
#define IS_ALIGNED(x, a)        (((x) & ((typeof(x))(a) - 1)) == 0)

#define SECTION_SHIFT           20
#define SECTION_SIZE            (1UL << SECTION_SHIFT)
#define SECTION_MASK            (~(SECTION_SIZE-1))

#define PTRS_PER_PTE 512
#define PAGE_SHIFT 12
#define __phys_to_virt(x)       ((x) - 0x50000000 + 0xc0000000)
#define __va(x)                 ((void *)__phys_to_virt((unsigned long)(x)))

static inline unsigned long *pmd_page_vaddr(unsigned long pmd)
{
        unsigned long ptr;

        ptr = (unsigned long)pmd  & ~(PTRS_PER_PTE * sizeof(void *) - 1);
        printf("ptr:%lx\n", ptr);
        ptr += PTRS_PER_PTE * sizeof(void *);

        return __va(ptr);
}

#define __pte_index(addr) (((addr) >> PAGE_SHIFT) & (PTRS_PER_PTE - 1))
#define pte_offset_kernel(dir, addr) (pmd_page_vaddr(*(dir)) + __pte_index(addr))

/* Find an entry in the third-level page table.. */
#define __pte_index(addr)       (((addr) >> PAGE_SHIFT) & (PTRS_PER_PTE - 1))

#define pte_offset_kernel(dir,addr)     (pmd_page_vaddr(*(dir)) + __pte_index(addr))
#define hotcpu_notifier(fn, pri) do { } while (0)

int hello(char *test)
{
	printf("%s\n", test);
	return 1;
}

int main()
{
	int a = 0 ,i = 0;
	int *p = &a;
	int b = -10;
	
	for(; i < 6; i++)
		printf("ALIGN(%d, 4): %x\n", i, ALIGN(i, 4));
		
	printf("p:%p, PTR_ALIGN(p, 8): %p\n", p, PTR_ALIGN(p, 8));
	printf("IS_ALIGNED(7, 8): %d, IS_ALIGNED(16, 8): %d\n", IS_ALIGNED(7, 8), IS_ALIGNED(16, 8));

//	printf("%lx, %x, %d\n", 0x5074034b & (0x0f << 2), b >> 10, system_state);
//	hotcpu_notifier(hello, "123");
	return 0;
}

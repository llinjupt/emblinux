#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

/* include/linux/types.h */
#define DECLARE_BITMAP(name, bits) \
	unsigned long name[BITS_TO_LONGS(bits)]

void dump_bitmap(unsigned long *dst, int nbits)
{
	printf("Hex dump bitmap: ");
	if(nbits <= BITS_PER_LONG)
		printf("%08lx\n", *dst);
	else
	{
		int len = BITS_TO_LONGS(nbits);
		int i = len - 1;
		for(; i >= 0; i--)
			printf("%08lx ", dst[i]);
		
		printf("\n");
	}
}

int main()
{
#define TEST_BITMAP_SIZE 60
	/* same as unsigned long bitmap[2] */
	DECLARE_BITMAP(bitmap, TEST_BITMAP_SIZE);
  DECLARE_BITMAP(bitmap1, TEST_BITMAP_SIZE);
  DECLARE_BITMAP(dst, TEST_BITMAP_SIZE);
  
  bitmap[0] = ~0UL;
  bitmap[1] = ~0UL;
  printf("sizeof(bitmap):\t%d\n", sizeof(bitmap));
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  
	bitmap_zero(bitmap, TEST_BITMAP_SIZE);
	bitmap_zero(bitmap1, TEST_BITMAP_SIZE);
	bitmap_zero(dst, TEST_BITMAP_SIZE);
	dump_bitmap(bitmap, TEST_BITMAP_SIZE);
	
	bitmap_fill(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);

  bitmap_and(dst, bitmap1, bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);
  
  printf("test bitmap_or\n");
  bitmap_or(dst, bitmap1, bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap1, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);
  
  printf("test bitmap_xor\n");
  bitmap_zero(bitmap, TEST_BITMAP_SIZE);
  bitmap_fill(bitmap1, TEST_BITMAP_SIZE);
  bitmap_xor(dst, bitmap1, bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap1, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);  
  
  printf("test bitmap_andnot\n");  
  bitmap_fill(bitmap, TEST_BITMAP_SIZE + 4);
  bitmap_andnot(dst, bitmap, bitmap1, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap1, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);  
  
  printf("test bitmap_complement\n");
  bitmap_zero(bitmap, TEST_BITMAP_SIZE); 
  bitmap_complement(dst, bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE); 
  dump_bitmap(dst, TEST_BITMAP_SIZE); 
  
  printf("test bitmap_equal\n");
  bitmap_complement(dst, dst, TEST_BITMAP_SIZE + 4);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE); 
  dump_bitmap(dst, TEST_BITMAP_SIZE); 
  printf("bitmap_equal:%d\n", bitmap_equal(bitmap, dst,TEST_BITMAP_SIZE));
  
  printf("test bitmap_intersects\n");
  bitmap_complement(dst, bitmap, TEST_BITMAP_SIZE);

  bitmap_fill(bitmap, 8);
	bitmap_fill(dst, 4);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);

  printf("bitmap_intersects: %d\n", bitmap_intersects(dst, bitmap, 8));
  printf("bitmap_subset: %d\n", bitmap_subset(dst, bitmap, 5));
  
  bitmap_zero(dst, 4);  
  dump_bitmap(dst, TEST_BITMAP_SIZE);
  printf("bitmap_empty: %d\n", bitmap_empty(dst, 33));
  bitmap_fill(dst, 4);  
  dump_bitmap(dst, TEST_BITMAP_SIZE);
  printf("bitmap_full: %d\n", bitmap_full(dst, 5));
  
  printf("bitmap_shift_right\n");  
  bitmap_fill(bitmap, TEST_BITMAP_SIZE + 4);
  dump_bitmap(bitmap, TEST_BITMAP_SIZE);
  dump_bitmap(dst, TEST_BITMAP_SIZE);
 	bitmap_shift_right(dst, bitmap, 2, TEST_BITMAP_SIZE);
 	dump_bitmap(dst, TEST_BITMAP_SIZE);
  printf("__bitmap_shift_left\n");  
 	__bitmap_shift_left(dst, bitmap, 200, TEST_BITMAP_SIZE);
 	dump_bitmap(dst, TEST_BITMAP_SIZE);

  /*int j = 0;
  for(; j < 60; j++)
  	printf("%d: %lx\n", j, BITMAP_LAST_WORD_MASK(j));*/
  	
  return 0;
}

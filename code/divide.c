#include <stdio.h>

static inline unsigned long timer_mask_usec_ticks(unsigned long scaler, unsigned long pclk)
{
	unsigned long den = pclk / 1000;

	return ((1000 << 16) * scaler + (den >> 1)) / den;
}
#define __raw_spin_is_locked(lock)      ((void)(lock), 0)

static inline void ____atomic_set_bit(unsigned int bit, volatile unsigned long *p)
{
        unsigned long flags;
        unsigned long mask = 1UL << (bit & 31);

        p += bit >> 5;

//        raw_local_irq_save(flags);
        *p |= mask;
//        raw_local_irq_restore(flags);
}


int main()
{
	unsigned long test = 0 ;
        unsigned long *p  = &test;
	____atomic_set_bit(1, p);

	return *p;
}


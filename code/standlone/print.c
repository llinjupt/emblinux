#define S3C64XX_GPMPUD (0x7F008828)
#define S3C64XX_GPMDAT (0x7F008824)
#define S3C64XX_GPMCON (0x7F008820)
static on = 0;
void led()
{
	unsigned long tmp = 0;
        //gpm0-3 pull up
        tmp = *((unsigned long *)(S3C64XX_GPMPUD));
        tmp &= (~0xff);
        tmp |= 0xaa;
        *((unsigned long *)(S3C64XX_GPMPUD)) = tmp;

        //gpm0-3 output mode
        tmp = *((unsigned long *)(S3C64XX_GPMCON));
        tmp &= (~0xffff);
        tmp |= 0x1111;
        *((unsigned long *)(S3C64XX_GPMCON)) = tmp;

        //gpm0-3 output 0
        tmp = *((unsigned long *)(S3C64XX_GPMDAT));
        if(on)
          tmp &= 0x0f;
	else
          tmp |= ~0x0f;
	on = !on;
        *((unsigned long *)(S3C64XX_GPMDAT)) = tmp;
}

void delay()
{
	unsigned i = 0, j = 0;
 	for(; i < 1000; i++)
 		for(j = 0; j < 10; j++)
		{
		}
}

void led_ctrl()
{
  while(1)
 {
   led();
   delay();
 }
}

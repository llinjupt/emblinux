.section .text
.align 2
.global _start
_start:
 ldr sp, =1024*4
 b led_ctrl

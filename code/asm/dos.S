.section .text
.align 2

.global main
main:
 mov r0, #0			/* without 's' */
 mrs r1, cpsr
 movs r0, #0    /* with s */
 mrs r2, cpsr
 bl print
 mov r0, #0
 bl quit

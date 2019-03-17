.section .text
.align 2

.global main
main:
 mrs r0, cpsr
 movs r3, #1
 mrs r1, cpsr
 movs r3, #-1
# mrs r2, cpsr
 mov r2, #0xafffffff
 bl print
 bl quit

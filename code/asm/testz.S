.section .text
.align 2

.macro	testz, cmd 
 movs r0, #0
 mrs r1, cpsr
 mov r2, #0
 \cmd r2, #1 
 bl print

.endm
.global main
main:
 testz moveq
 testz movne
 mov r0, #0
 bl quit

.section .text
.align 2

.global main
main:
 mrs r0, cpsr 
 orr r0, #0x1F
 msr cpsr_f, r1
 mrs r1, cpsr
 mov r2, #0 
 bl print
 mov r0, #0
 bl quit

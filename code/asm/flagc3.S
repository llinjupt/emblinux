.section .text
.align 2

.global main
main:
 /* clean all condition flags */
 msr cpsr_f, #0
 
 /* make sure the adds result won't overflow */
 mov r3, #0x7ffffffe
 adds r3, r3, #1
 mrs r1, cpsr 

 /* overflowed let cpsr->r2 */
 adds r3, r3, #1
 mrs r2, cpsr

 mov r0, r3
 bl print
 bl quit

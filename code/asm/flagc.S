.section .text
.align 2

.global main
main:
 /* clean all condition flags */
 msr cpsr_f, #0
 
 /* make sure the add result is not overflow and 
  let cpsr->r1 */
 mov r3, #0xfffffffe  
 adds r3, r3, #1
 mrs r1, cpsr 

 /* overflow let cpsr->r2 */
 adds r3, r3, #1
 mov r0, r3

 bl print
 bl quit

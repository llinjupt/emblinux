.section .text
.align 2

.global main
main:
 /* clean all condition flags */
 msr cpsr_f, #0
 
 /* make sure the sub result won't borrow and 
  let cpsr->r1 */
 mov r3, #0x1
 subs r3, r3, #1
 mrs r1, cpsr 

 /* borrowed let cpsr->r2 */
 subs r3, r3, #1
 mrs r2, cpsr

 ror r0, r3
 bl print
 bl quit

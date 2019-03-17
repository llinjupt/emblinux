.section .text
.align 2

.global main
main:
 /* save orig cpsr->r0 */
 mrs r0, cpsr 

 /* give a non-Neg value get cpsr->r1 */
 movs r3, #1  
 mrs r1, cpsr 

 /* give a Neg value get cpsr->r2 */
 movs r3, #-1
 mrs r2, cpsr

 bl print
 bl quit

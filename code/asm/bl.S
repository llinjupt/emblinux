.section .text
.align 2

.global main
main:
over:
 mov r0, #12
 bl over
 mov r1, #34
 mov r2, #56
#.global over
#over:
 mov r0, #0
 bl quit

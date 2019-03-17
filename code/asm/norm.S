.section .text
.align 2

.global main
main:
 mov r0, #12
 mov r1, #34
 mov r2, #56
 bl print
 mov r0, #0
 bl quit

.section .text
.align 2

.global main
main:
 mov r0, #0x12
 mov r1, #0x34
 mov r2, #0x56
 bl print
 mov r0, #0
 bl quit

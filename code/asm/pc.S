.section .text
.align 2

.global main
main:
 mov r0, pc	@ pc always indicates pc(fetch)
 bl print
 bl quit

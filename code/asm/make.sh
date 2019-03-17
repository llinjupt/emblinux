arm-linux-gcc  print.c  $1 -o test #-g
arm-linux-objdump -D test >tmp
cp -f test /home/red/tftp/

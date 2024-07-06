set env LD_LIBRARY_PATH .
b *0x8049395
run secret.cry
set $eax=0x1
c
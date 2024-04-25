extern void __STACK__; /* extern = defined outside the scope, in this case, in the linker script (.id)*/

void __attribute__((naked)) _start() //naked = menos assembly; fastcall = argumento em cx ao invez de pilha
{
__asm__ volatile
  ("\
                mov  $__STACK__ ,     %%sp \n\
                call main                  \n\
     loop%=:                               \n\
                hlt                        \n\
                jmp loop%=                 \n\
   "
   :::
   );
} /*default startup for programs (initialize stack, call main and return to OS or halt as in our case) */
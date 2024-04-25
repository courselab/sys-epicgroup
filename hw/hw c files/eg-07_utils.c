void __attribute__((fastcall, naked))  print(const char* s) /*through fastcall, parameters (s) goes to cx and retval to ax; through naked, assembly code*/
{
__asm__ volatile
("\
	mov   %cx,	%bx				\n\
	mov   $0x0e, %%ah           \n\
	mov   $0x0, %%si            \n\
loop%=:	          		    	\n\
	mov   (%%bx, %%si), %%al    \n\
	cmp   $0x0, %%al	    	\n\
	je    end%=                 \n\
	int   $0x10	            	\n\
	add   $0x1, %%si	    	\n\
	jmp   loop%=	            \n\
end%=:                          \n\
    ret                         \n\
"
 ); /*through volatile, the compiler will not try to apply optimizations and will just past the asm as is*/
}

/*

	mov   %cx,	%bx			//cx to bx (parameter received to iterable register)
	mov   $0x0e, %%ah     //14 to ah (BIOS to teletype mode)      
	mov   $0x0, %%si      //0 to si (index starts at 0)      
loop%=:	          		    
	mov   (%%bx, %%si), %%al //Character at *(bx + si) to al    
	cmp   $0x0, %%al	    
	je    end%=              //if al equals to 0 (\0), end   
	int   $0x10	            //call INT 10 (write on video)
	add   $0x1, %%si	    //next character
	jmp   loop%=	            
end%=:                                         
        ret                         


*/
OUTPUT_FORMAT(binary)		
SECTIONS
{
        . = 0x7c00;		/* starts at 0x7c00. */
        .text :
	{
		*(.text)              
		*(.rodata)		
	}	
        . = 0x7c00 + 510;	
        .signature : 		/* Bootable image signature at the end (last 2 bytes of the 512 bytes block) */
	{
	    BYTE(0x55)
        BYTE(0xAA)
    }
	__STACK__ = 0x8000; /*0x7e00 + 0x200 for the end of the stack*/	
}
STARTUP(eg-07_rt0.o);
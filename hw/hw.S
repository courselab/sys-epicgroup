# Hello World

	.code16			#Modo 16 bit
	
	.global _start		#ponto de entrada padrao para o linker

_start:				#comeca o programa
	
	movb	$0xe,	%ah	#seleciona BIOS

	movW	$0x0,	%bx	#indice de iteracao
	
loop:
	movb	msg(%bx), %al	#offset para cada caractere na menssagem
	cmp	$0x0,	%al	#loop enquanto o char 0x0 (fim da string)  nao for atingido
	je	halt		#pula para o halt se a comparacao for verdadeira
	int	$0x10		#faz a call para o servico de video da BIOS
	add	$0x1,	%bx	#aponta para o proximo caractere
	jmp	loop		#Repete ate o fim da string

halt:
	hlt			#Halt
	jmp	halt		#safeguard

msg:	
	.string	"Hello World TEST"	#ja adiciona o 0x0 no fim

	.fill	510 - (. -  _start), 1, 0	#adiciona zeros
	.word	0xaa55				#assinatura de boot

	.text
	.globl main
main:
	li $v0, 5  # le num inteiro de entrada
	syscall
	
	move $s0, $v0  # s0 = v0
	li $s1, 1  # s1 = 1
while:
	mult $s0, $s1  # s0 * s1
	mflo $s1  # move os 32 bits mais sinificativos da multiplicacao para s1 
	addi $s0, $s0, -1  # s0 -= 1
 	bnez $s0, while  # while (s0 != 0)
	
	move $a0, $s1  # a0 = s1
	li $v0, 1  # chama a funcao para printar o conteudo de a0
	syscall
end:
	li $v0, 10 # encerra 
	syscall
	

	.data
	par: .asciiz "Par\n"
	impar: .asciiz "Impar\n"
	endl: .asciiz "\n"
	entrada: .asciiz "Digite numeros, zero para terminar\n"
	
	.text
	.globl main
main:
	li $v0, 4
	la $a0, entrada
	syscall
	li $s0, 2  # guarda o valor 2 para usar na divisão

while:
	li $v0, 5  # lê um inteiro e armazena em s1
	syscall
	move $s1, $v0
	
	beqz $s1, end  # se o inteiro == 0 finaliza o programa
	
	div $s1, $s0  # s1/s0
	mfhi $t0  # t0 = s1 % s0
	beqz $t0, branchPar  # se t0 == 0 imprimi par
	j branchImpar  # senao imprimi impar

branchPar:
	li $v0, 4  # imprimi par
	la $a0, par
	syscall
	j while  # volta para while
	
branchImpar:
	li $v0, 4  # imprimi impar
	la $a0, impar
	syscall
	j while  # volta para while

end: 
	li $v0 , 10  # saida do programa
	syscall
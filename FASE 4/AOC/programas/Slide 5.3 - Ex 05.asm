	.data
	entrada: .asciiz "Digite o valor\n"
	endl: .asciiz "\n"
	esp: .asciiz " "
cedulas:
	.word 50
	.word 20
	.word 10
	.word 5
	.word 1

	.text
	.globl main
main:
	li $v0, 4  # printa requisitando a entrada do usuário
	la $a0, entrada
	syscall
	
	li $v0, 5  # lê a entrada do usuário e armazena em s0
	syscall
	move $s0, $v0
	
	la $s1, cedulas  # carrega a cedula para s1
	li $s4, 5  # iterador vetor
while:
	lw $s2, 0($s1)  # carrega a cedula atual para s2
	li $s3, 0  # salva a qt de cedulas

ctgCedulas:
	blt $s0, $s2, avanca  # se s0 < s2 avanca vetor
	sub $s0, $s0, $s2  # s0 -= s2
	addi $s3, $s3, 1  # s3++
	bnez $s0, ctgCedulas  # se s0 != 0 continuar ctgCedulas
	
avanca:
	li $v0, 1  # printa a contagem de cedulas atual
	move $a0, $s3
	syscall
	
	li $v0, 4  # printa espaço
	la $a0, esp
	syscall
	
	addi $s4, $s4, -1  # diminui um no indice do vetor 
	addi $s1, $s1, 4  # pula para a proxima posição do vetor 
	bnez $s0, while  # se s0 != 0 pula para while
	beq $s4, $zero, end  # se s4 == 0 pula para o final, todas as cedulas foram printadas

zeroFinal:  # funcao que serve para printar zeros quando já concluimos o valor mas ainda há cedulas sem qt printada
	li $v0, 1
	move $a0, $zero
	syscall
	addi $s4, $s4, -1
	bnez $s4, zeroFinal
end:
	li $v0, 10  # encerra o programa
	syscall

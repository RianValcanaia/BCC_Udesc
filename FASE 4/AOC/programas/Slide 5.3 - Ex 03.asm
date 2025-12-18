	.data
	msgerro: .asciiz "ERRO\n"
	endl: .asciiz "\n"
	
	.text
	.globl main	
main: 
	li $s0, 0  # s0 armazenará a soma 
	li $s1, 0  # armazena a quantidade de entradas
	li $s2, -1  # armazena -1 no s2
	li $s3, 2048  # armazena o valor final 2048
while: 
	li $v0, 5  
	syscall
	move $s4, $v0  # le um inteiro e guarda em s4
	add $s0, $s0, $s4  # s0 += s3
	addi $s1, $s1, 1  # s1 += 1
	bge $s0, $s3, resultado
	bne $s4, $s2, while
	
resultado:
	addi $s1, $s1, -1  # diminui a quantidade de entradas 
	addi $s0, $s0, 1  # soma 1 para s0
	
	move $a0, $s0  # printa a soma
	li $v0, 1   
	syscall
	
	beq $s0, $zero, erro  # tratamento de erro se a quantidade de elementos for 0
	
	li $a0, 10 # printa quebra de linha
	li $v0, 11  
	syscall
	
	div $s0, $s1  # printa a divisao inteira
	mflo $a0
	li $v0, 1  
	syscall	
	
	j end  # pula para o end
erro:
	li $v0, 4
	la $a0, endl
	syscall
	
	li $v0, 4
	la $a0, msgerro
	syscall
	
	j end  # pula para o end
end:
	li $v0, 10
	syscall

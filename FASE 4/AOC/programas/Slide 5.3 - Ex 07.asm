	.data
	barra: .asciiz "/"
	endl: .asciiz "\n"
	entrada: .asciiz "Digite os dias da sua idade:\n"
	
	.text
	.globl main
	
main: 
	li $v0, 4  # printa para digitar a entrada
	la $a0, entrada
	syscall
	
	li $v0, 5  # lê a entrada
	syscall
	move $s1, $v0
	
	li $t0, 365  # divide a data por 365
	div $s1, $t0
	mflo $s1
	mfhi $s2
	
	li $v0, 1  # printa os anos
	move $a0, $s1
	syscall
	
	li $v0, 4  # printa barra
	la $a0, barra
	syscall
	
	li $t0, 31  # divide para achar os meses
	div $s2, $t0
	mflo $s2
	mfhi $s1
	
	li $v0, 1  # printa os meses
	move $a0, $s2
	syscall
	
	li $v0, 4  # printa a barra
	la $a0, barra
	syscall
	
	li $v0, 1  # printa os dias
	move $a0, $s1
	syscall
	
end:
	li $v0, 10
	syscall
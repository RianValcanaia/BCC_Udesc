	.data
	endl: .asciiz "\n"
	.text
	.globl main
main:
	li $s0, 2
	li $s1, 0
while: 
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 11
	li $a0, 120
	syscall
	
	li $v0, 1
	move $a0, $s1
	syscall
	
	li $v0, 11
	li $a0, 61
	syscall
	
	mult $s0, $s1
	mflo $a0
	
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	addi $s1, $s1, 1
	li $t0, 10
	bne $s1, $t0, while
	
	li $v0, 4
	la $a0, endl
	syscall
	
	addi $s0, $s0, 1
	li $s1, 0
	bne $s0, $t0, while
end:
	li $v0, 10
	syscall
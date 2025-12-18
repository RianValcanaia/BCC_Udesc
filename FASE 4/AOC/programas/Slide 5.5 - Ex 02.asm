	.text
	.globl main
main:
	li $v0, 5
	syscall 
	move $a0, $v0
	
	li $v0, 5
	syscall
	move $a1, $v0

	jal f_maior
	
	move $a0, $v0
	li $v0, 1
	syscall
	j end
	
f_maior:
	bge $a0, $a1, f_maior_pri
	move $v0, $a1
	jr $ra
	
f_maior_pri:
	move $v0, $a0
	jr $ra
	
end: 
	li $v0, 10
	syscall
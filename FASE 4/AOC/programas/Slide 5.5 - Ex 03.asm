	.text
	.globl main
main:
	li $v0, 5
	syscall 
	move $a0, $v0
	
	li $v0, 5
	syscall
	move $a1, $v0
	
	li $v0, 5
	syscall
	move $a2, $v0

	jal f_maior
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 11
	li $a0, 10
	syscall
	
	move $a0, $v1
	li $v0, 1
	syscall
	
	j end
	
f_maior:
	# salva contexto
	add $sp, $sp, -8
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	
	# comeca maior e menor sendo a0
	move $s0, $a0
	move $s1, $a0
	
	bge $a1, $s0, f_maior_a1
	bge $a2, $s0, f_maior_a2
	bge $a1, $a2, f_menor_a22
	move $s1, $a1
	
	j continuar
	
f_maior_a1:
	bge $a2, $a1, f_maior_a2
	move $s0, $a1
	
f_menor_a0:
	bge $s0, $a2, f_menor_a2
	move $s1, $a0
	j continuar
	
f_menor_a2:
	move $s1, $a2
	j continuar
	
f_maior_a2:
	move $s0, $a2
	j continuar
	
f_menor_a22:
	move $s1, $a2

continuar:
	move $v0, $s0
	move $v1, $s1

	# restaura 
	add $sp, $sp, -8
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	
	jr $ra
	
end: 
	li $v0, 10
	syscall

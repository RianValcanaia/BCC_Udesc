	.text
	.globl main

main:
	li $v0, 5
	syscall
	move $a0, $v0
	
	jal f_conta_digitos
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	j end
	
f_conta_digitos:
	beqz $a0, f_parada
	
	# salva contexto
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	li $t0, 10
	div $a0, $t0
	mflo $a0
	
	jal f_conta_digitos
	addi $v0, $v0, 1
	
	# recupera da pilha
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra
	
f_parada:
	li $v0, 0
	jr $ra
end:
	li $v0, 10
	syscall
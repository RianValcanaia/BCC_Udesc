	.data
	entradaX: .asciiz "Digite a coordenada x\n"
	entradaY: .asciiz "Digite a coordenada y\n"
	prim: .asciiz "Primeiro Quadrante\n"
	seg: .asciiz "Segundo Quadrante\n"
	ter: .asciiz "Terceiro Quadrante\n"
	quar: .asciiz "Quarto Quadrante\n"
	ex: .asciiz "Eixo X\n"
	ey: .asciiz "Eixo y\n"
	orig: .asciiz "Origem\n"
	.text
	.globl main

main:
	li $v0, 4
	la $a0, entradaX
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0
	
	li $v0, 4
	la $a0, entradaY
	syscall
	
	li $v0, 5
	syscall
	move $s1, $v0
	
	bgtz $s0, primQua
	bltz $s0, segQua
	j eixoX
	
primQua:
	blez $s1, quarQua
	li $v0, 4
	la $a0, prim
	syscall
	j end
	
segQua:
	blez $s1, terQua
	li $v0, 4
	la $a0, seg
	syscall
	j end
terQua:
	beqz $s1, eixoX
	li $v0, 4
	la $a0, ter
	syscall
	j end
	
quarQua:
	beqz $s1, eixoY
	li $v0, 4
	la $a0, quar
	syscall
	j end

eixoY:
	li $v0, 4
	la $a0, ey
	syscall
	j end
	
eixoX:
	beqz $s1, origem
	li $v0, 4
	la $a0, ex
	syscall	
	j end
origem:
	li $v0, 4
	la $a0, orig
	syscall	

end:
	li $v0, 10
	syscall
	.data 
	msgCin: .asciiz "Digite a posição da seq. de fibonacci\n"
	endl: .asciiz "\n"
	
	.text
	.globl main
main:
	# código em C:
	# int a = 0, b = 1, temp, pos;
	# while (pos--){
	# 	temp = a;
	# 	a = b;
	# 	b = a+temp;
	# }
	# printf("%d\n", a);

	li $v0, 4
	la $a0, msgCin 
	syscall  # printa a mesagem inicial
	
	li $v0, 5
	syscall
	move $s0, $v0  # lê um inteiro de entrada s0 = v0
	
	li $s1, 0  # s1 = a = 0  
	li $s2, 1  # s2 = b = 1
while:
	move $t0, $s1  # temp = s1 = a
	move $s1, $s2  # s1 = s2 (a = b)
	add $s2, $s1, $t0  # b = a + temp
	addi $s0, $s0,  -1
	bnez $s0, while
end:
	
	li $v0, 1  # printa o resultado
	move $a0, $s1
	syscall

	li $v0, 10
	syscall

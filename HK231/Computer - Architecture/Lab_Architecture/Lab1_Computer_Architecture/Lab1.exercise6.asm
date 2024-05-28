.data
	s1: .asciiz "Input a binary value: \n "
	r1: .asciiz "\n Your decimal result is: "
.text
	li $v0, 4
	la $a0, s1
	syscall
	li $v0, 5
	syscall
	move $t0, $v0		#input binary number
	
	
	li $t1, 1
	jal toDec
	
	li $v0, 4
	la $a0, r1
	syscall
	
	li $v0, 1
	add $a0, $0, $t3			#$t3 is the result
	syscall
	li $v0, 10
	syscall
	
toDec:
	beq $t0, 0, exit
	remu $t2, $t0, 10			#remainder instruction
	divu $t0, $t0, 10 	
	mul $t2, $t2, $t1
	add $t3, $t3, $t2
	sll $t1, $t1, 1				#each loop multiply $t1 to 2
	j toDec
exit: 
	jr $ra
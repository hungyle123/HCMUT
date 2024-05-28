.data
	
	array: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
	s1: .asciiz "******Choose a mode: \n 0. Exit \n 1. Print value at \n 2. Print sequence \n"
	s2: .asciiz "Input an index you want:  \n"
	s3: .asciiz "Input lower bound:  \n"
	s4: .asciiz "Input upper bound:  \n"
	r1: .asciiz "Your value is: "
	r2: .asciiz "Your sequence is: "
	c: .asciiz "\n Press 1 to continue \n"
.text

main:	
	li $v0, 4
	la $a0, s1
	syscall
	li $v0, 5
	syscall
	beq $v0, 0, exit
	beq $v0, 1, value
	beq $v0, 2, sequence
	j main
	
back:
	jr $ra

loop:
	slt   $t3, $t7, $t2        
	beq $t3, $zero, back 
	addi    $t5, $t5, 4
	addi    $t7, $t7, 1
	j loop
		
loops:
	slt $t3, $t9, $t2
	beq $t3, $zero, back
	addi    $t5, $t5, 4
	addi    $t9, $t9, 1
	j loops
sloop:
	slt   $t3, $t2, $t7        
	beq $t3, $zero, back
	li $v0, 1
	lw $a0, ($t5)
	syscall
	addi    $t5, $t5, 4
	addi    $t2, $t2, 1
	j sloop	


value:
	li $v0, 4
	la $a0, s2
	syscall
	li $v0, 5
	syscall
	move $t2, $v0
	la $t5, array
	li $t4, -1
	beq $v0, -1, main
	slti $t1, $v0, 15
	slt $t8, $t4, $v0
	add $t1, $t1, $t8
	bne $t1, 2, value
	jal loops
	li $v0, 4
	la $a0, r1
	syscall
	li $v0, 1
	lw $a0, ($t5)
	syscall
	j exit	
	

sequence:
	la $t5, array
	li $v0, 4
	la $a0, s3
	syscall
	li $v0, 5
	syscall
	move $t2, $v0
	beq $t2, -1, main
	li $v0, 4
	la $a0, s4
	syscall
	li $v0, 5
	syscall
	move $t7, $v0
	beq $t7, -1, main
	slt $t1, $t2, $t7
	bne $t1, 1, sequence
	li $t4,-1
	slt $t1, $t4, $t2
	bne $t1, 1, sequence
	slti $t1, $t7, 15
	bne $t1, 1, sequence 
	addi $t7, $t7, 1
	jal loops
	li $v0, 4
	la $a0, r2
	syscall
	jal sloop
	j exit
	
exit: 
	li $v0, 10
	syscall
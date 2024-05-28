.data 
	s1: .asciiz "Input N: \n"
	s2: .asciiz "Input M: \n"
	s3: .asciiz "Input X: \n"
.text
	li $v0, 4
	la $a0, s1
	syscall
	li $v0, 5
	syscall				#input N
	addi $s1, $v0, 0
	
	li $v0, 4
	la $a0, s2
	syscall
	li $v0, 5
	syscall
	addi $s2 , $v0, 0		#input M
	
	li $v0, 4
	la $a0, s3
	syscall
	li $v0, 5
	syscall
	addi $s3, $v0, 0			#input X
	
	addi $t0, $0, 0
	add  $t1, $0, $s1
	jal loop
	li $v0, 10
	syscall
	
loop:
	beq $t0, $s3, exit
	li $v0, 1
	add $a0, $0, $t1
	syscall
	
	li $v0, 11 			# print space
    	li $a0, ' '	 
    	syscall
	
	
	addi $t0, $t0, 1
	mul $t1, $t1, $s2
	j loop
	
exit:
	jr $ra

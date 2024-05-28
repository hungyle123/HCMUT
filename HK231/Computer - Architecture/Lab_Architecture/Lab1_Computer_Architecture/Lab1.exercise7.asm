.data
	str1: .asciiz "Input a number n : "
	str2: .asciiz "Output factorial : "
.text
main: 
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 5
	syscall
	move $s1, $v0
	
	addi $s0, $0, 0
	addi $t0, $0, 1
loop:
	mul $t0, $t0 ,$s1
	addi $s1, $s1, -1
	bne $s1,$s0, loop
	
	li $v0, 11 			
    	li $a0, ' '	 #print space
    	syscall
	
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 1
	add $a0, $0, $t0
	syscall
	
	li $v0, 10
	syscall		

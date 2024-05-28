.data 
	a: .word 5
	b: .word 3
	c: .word 10
	d: .word 2
	str1: .asciiz "F = "
	#strline: . asciiz"\n"
	str2: .asciiz "G = "
.text
main:
	lw $s1, a
	lw $s2, b
	lw $s3, c
	lw $s4, d
	
	add $t1, $s1 ,$s2		#$t1 = a + b		
	sub $t2, $s3 ,$s4		#$t2 = c -d 
	mul $t0, $s1 , $s1		#$t3 = a^2
	
	mul $s5, $t1 , $t2
	div $s5, $s5 ,$t0		#$s5 is final result
	
	la $a0, str1
	li $v0, 4
	syscall
	
	add $a0, $0 , $s5			#print the result F 
	li $v0, 1 
	syscall
	
	li $v0, 11 			
    	li $a0, ' '	 
    	syscall
	
	addi $t1, $s1, 1			#$t1 = a + 1
	addi $t2, $s2, 2			#$t2 = b + 2
	addi $t3, $s3, -3			#$t3 = c - 3
	sub  $t4, $s3, $s1			#$t4 = c - a
	
	mul  $s1, $t1, $t2
	mul  $s1, $s1, $t3
	div  $s1, $s1, $t4			#$s1 is final result 
	
	la $a0, str2
	li $v0, 4
	syscall
	
	add $a0, $0 , $s1			#print the result G
	li $v0, 1 
	syscall
	
	li $v0, 10
	syscall

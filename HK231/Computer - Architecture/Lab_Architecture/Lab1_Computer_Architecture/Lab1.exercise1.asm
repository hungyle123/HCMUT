.data
	cout: .asciiz "The result is : "
	print1: .asciiz "Input your first number: "
	print2: .asciiz "Input your second number: "
	print3: .asciiz "Operator: \n 1. + \n 2. - \n 3. * \n 4. / \n"
.text
main:
	la $a0, print1
	li $v0, 4 
	syscall		#Input your first number:
	li $v0, 5
	syscall
	add $s1 , $0, $v0 # $s1 = firstnumber
	
	la $a0, print2
	li $v0, 4 
	syscall		#Input your second number:
	li $v0, 5
	syscall
	add $s2 , $0, $v0 # $s2 = firstnumber
	
	la $a0, print3
	li $v0, 4 
	syscall		#Which operator ?
	li $v0, 5
	syscall
	add $t0 , $0, $v0  #t0 choose the operator
	
	beq $t0, 1, sum        #goto the function 
	beq $t0, 2, minus
	beq $t0, 3, multiply
	beq $t0, 4, divide
	li $v0, 10
	syscall
	
sum:
	la $a0, cout
	li $v0, 4
	syscall
       	add $a0, $s1, $s2
       	li $v0, 1  		 	#print the sum
       	syscall
       	li $v0, 10
       	syscall
       
minus:
	la $a0, cout
	li $v0, 4
	syscall
       	sub $a0, $s1, $s2
       	li $v0, 1
       	syscall                   	#print the minus
       	li $v0, 10
       	syscall
multiply:
	la $a0, cout
	li $v0, 4
	syscall
       	mul $a0, $s1, $s2
       	li $v0, 1			 #print the multiply
       	syscall
       	li $v0, 10
       	syscall
divide:
	la $a0, cout
	li $v0, 4
	syscall
       	div $a0, $s1, $s2
       	li $v0, 1			 #print the divide
       	syscall
       	li $v0, 10
       	syscall
 
.data
	floatarray: .float 0,0,0,0,0,0,0,0,0,0
	input: .asciiz "Please input the float number "
	haicham: .asciiz ": "
	enter: .asciiz "\n"
	output: .asciiz "Sum of 10 float is : "
	
.text
	li $t0, 0
loop:
	beq $t0,10,next
	li $v0,4
	la $a0,input
	syscall
	
	li $v0,1
	move $a0,$t0
	addi $a0,$a0,1
	syscall
	
	li $v0,4
	la $a0,haicham
	syscall
	
	li $v0,6
	syscall
	sll $t2,$t0,2
	s.s $f0,floatarray($t2)
	
	addi $t0,$t0,1
	j loop
	
next:
	li $t0,0
	
	sw $t0, 0($sp)
	swc1 $f2,4($sp)
	
	jal recursion
	
	li $v0,4
	la $a0,enter
	syscall	
				
	li $v0,4
	la $a0,output
	syscall
		
		
	lwc1 $f12,8($sp)	
	li $v0,2
	syscall
	
	li $v0,10
	syscall


recursion:
	addi $sp, $sp, -12 
    	sw $ra, 0($sp) 
   	sw $t0, 4($sp) 
   	swc1 $f0, 8($sp) 
   	
   	lw $t0, 4($sp) 
    	beq $t0, 9, end
    	sll $t2,$t0,2
   	l.s $f2, floatarray($t2) 
   	lwc1 $f0, 8($sp) 
   	add.s $f0, $f0, $f2 
   	addi $t0, $t0, 1 
  	sw $t0, 4($sp)
   	swc1 $f0, 8($sp) 
   	jal recursion
  
end:
  	lw $ra, 0($sp)
   	lw $t0, 4($sp) 
    	lw $t1, 8($sp) 
    	addi $sp, $sp, 12
    	sw $t0, 4($sp)
   	sw $t1, 8($sp)
    	jr $ra

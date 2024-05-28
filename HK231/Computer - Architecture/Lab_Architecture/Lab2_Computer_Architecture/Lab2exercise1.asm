.data
	str1: .asciiz "Input a string :"
	str:  .space 1000
	array: .word 512		#An array store the number of frequency of each char
	str2: .asciiz ": "
	str3: .asciiz "; "
	str4: .asciiz "."
	str5: .asciiz "You has just input a non-alphabet string. Please input a string again:"
	
.text
	li $v0,4			#print str1
	la $a0,str1
	syscall


	la $a0,str			#get an input string from user
	addi $a1,$0,1000
	li $v0,8
	syscall
	
	jal checknumber


	li $t0,0			#initialize
	
loopstring:
	lb $s0,str($t0)			#get each char to compare if it is null or line feed we stop the loop
	beq $s0,$0,exit			
	beq $s0,10,exit
	sll $s0,$s0,2
	lw $s1,array($s0)		#store the frequency
	addi $s1,$s1,1
	sw $s1,array($s0)
	
	addi $t0,$t0,1
	j loopstring
exit:

	li $s0,1
	addi $t0,$t0,1
	move $s7,$t0		#$s7 = length string + 1
	li $s6,1		#boolean $s6 for print the first time
	
loop1:
	beq $s0,$s7,end
				
	li $t0,127
loop2:
	beq $t0,-1,increase1		#We have initialize the $s0 = 1 and we stare to loop from 127 back to 0
	
	sll $t1,$t0,2			#get index address
	lw $s1,array($t1)
	bne $s1,$s0, increase2		#if it not the value frequency we want to print get to the next one
	
	beq $s6,1,next
	li $v0,4
	la $a0, str3
	syscall
	j next1
	
next:	li $s6,0			#When $s6 is 0 we start to print value -> : -> number of frequency
next1:
	li $v0,11
	move $a0,$t0
	syscall
	
	li $v0,4
	la $a0, str2
	syscall
	
	li $v0,1
	move $a0,$s0
	syscall
	
increase2:
	sub $t0,$t0,1
	j loop2
	
increase1:
	addi $s0,$s0,1
	j loop1

end:
	li $v0,4			#print "."
	la $a0,str4
	syscall
	
	li $v0,10
	syscall

checknumber:
refalse:
	li $t0,0
	
	lb $s1,str($t0)
	beq $s1,0,false
	beq $s1,10,false
	
loopchecknumber:
	li $t1,0
	lb $s1,str($t0)
	beq $s1,0,endchecknumber
	beq $s1,10,endchecknumber
	
	slti $s5,$s1,91
	beq $s5,0,continue1
	addi $t1,$t1,1
continue1:
	li $s2,64
	slt $s5,$s2,$s1
	beq $s5,0,continue2
	addi $t1,$t1,1
continue2:
	beq $t1,2,endchecknumberloop
	li $t1,0
		
	slti $s5,$s1,123
	beq $s5,0,continue3
	addi $t1,$t1,1
continue3:
	li $s2,96
	slt $s5,$s2,$s1
	beq $s5,0,continue4
	addi $t1,$t1,1
continue4:
	beq $t1,2,endchecknumberloop
	j false
endchecknumberloop:
	addi $t0,$t0,1
	j loopchecknumber

endchecknumber:
	jr $ra
	
false:
	li $v0,4
	la $a0,str5
	syscall
	
	la $a0,str			#get an input string from user
	addi $a1,$0,1000
	li $v0,8
	syscall
	
	j refalse

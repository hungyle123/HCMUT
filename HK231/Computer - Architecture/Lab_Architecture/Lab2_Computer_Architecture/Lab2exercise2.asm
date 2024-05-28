.data 
	str1: .asciiz "GCD = "
	str2: .asciiz "LCM = "
	str6: .asciiz ", "
	str3: .asciiz "Please input the first positive number:"
	str5: .asciiz "\nPlease input the second positve number:"
	str4: .asciiz "\nYou input a invalid number. The number must be positive. Please input again :"
	stringinput: .space 10000
	
.text
	li $v0, 4
	la $a0, str3
	syscall
	
	
repeat1:	
	la $a0,stringinput			#get input string and then convert to number
	addi $a1,$0,10000
	li $v0,8
	syscall
	
	li $s1,0				#Initialize
	li $t0,0
	lb $t1,stringinput($t0)
	beq $t1,10,false1			#We check the first element if the user input nothing we have to input again
	
loop1:	
	lb $t1,stringinput($t0)
	beq $t1,10,continue1			#end loop
	
	sub $t1,$t1,48				#get value each char number
	li $s4,0
	slt $s5,$t1,$s4				
	beq $s5,1,false1			#if the input get any input that ascii code is less than 48 (means less than 0) that an invalid input
	li $s4,10
	slt $s5,$s4,$t1
	beq $s5,1,false1
	
	mul $s1,$s1,10				#because we start from left to right so mul the first char to 10 and + the next one until done
	add $s1,$s1,$t1
	addi $t0,$t0,1
	j loop1

false1:	
	li $v0, 4				#when false means input invalid so the user have  to reinput
	la $a0, str4
	syscall
	
	j repeat1
	
	
continue1:	
	beq $s1,0,false1

	li $v0, 4
	la $a0, str5
	syscall

repeat2:	
	la $a0,stringinput			#the second number is doing the same but store the value in $s2
	addi $a1,$0,10000
	li $v0,8
	syscall
	
	li $s2,0
	li $t0,0
	lb $t1,stringinput($t0)
	beq $t1,10,false2
	
loop2:	
	lb $t1,stringinput($t0)
	beq $t1,10,continue2
	
	sub $t1,$t1,48
	li $s4,0
	slt $s5,$t1,$s4
	beq $s5,1,false2
	li $s4,10
	slt $s5,$s4,$t1
	beq $s5,1,false2
	
	mul $s2,$s2,10
	add $s2,$s2,$t1
	addi $t0,$t0,1
	j loop2

false2:	
	li $v0, 4
	la $a0, str4
	syscall
	
	j repeat2
	
	
continue2:
	beq $s2,0,false2
	
	
	move $s3,$s1				#we store the value of $s1 and $s2 in $s3 $s4 to compute LCM later
	move $s4,$s2
GCD:
	beq $s2,$0, exit1
	div $s1,$s2
	
	move $s1,$s2			#$s1 store GCD
	mfhi $t0
	move $s2,$t0
	j GCD

exit1:
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 1
	move $a0 ,$s1
	syscall
	
	li $v0, 4
	la $a0, str6
	syscall
	
LCM:
	div $t0,$s3,$s1			
	mul $t0, $t0,$s4
	
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0,10
	syscall	
	
	
	

.data
    array:.space 32       #4*8 bytes
    cout:.asciiz "Enter the 8 Elements :\n"
    str4: .asciiz "You input a invalid number. Please input again the recent value :"
    str: .asciiz "Please enter the element "
    str1: .asciiz ":"
    str2: .asciiz "The final array :"
    stringinput: .space 10000

.text   
	la $a0, cout
	li $v0,4
	syscall
	
	li $t0, 0
	li $t3, 1
input:	
	beq $t0,-32,continue		
   	
   	li $v0,4
   	la $a0,str
   	syscall
   	
   	li $v0,1
   	move $a0,$t3
   	syscall
   	
   	li $v0,4
   	la $a0,str1
   	syscall
   	
   	jal inputstring			#call procedure to input string and also check the input
   	
   	sw $s1,array($t0)		#Store array
        sub $t0,$t0,4	
        addi $t3,$t3,1	
   	j input	
		
continue:
	li $t0, 0
	
up:	beq $t0,-32,print
	lw $t1, array($t0)
	li $t3, 3
	div $t1,$t3			#We divide $t1/$t3 and get the remainder in HIGH
	mfhi $t2
	
	beq $t2,0,if0			#All case needed to do
	beq $t2,1,if1
	beq $t2,2,if2
	beq $t2,-1,if1n
	beq $t2,-2,if2n
	
if0:
	mflo $t1			#if = 0 so divide it to 3 
	sw $t1, array($t0)	
	j ground
if1:					#if = 1 minus it to 1
	sub $t1,$t1,1
	sw $t1, array($t0)	
	j ground	
if2:					#if = 2 add 1
	addi $t1,$t1,1
	sw $t1, array($t0)	
	j ground	
if1n:					#if = -1 add 1
	addi $t1,$t1,1
	sw $t1, array($t0)	
	j ground	
if2n:					#if = -2 minus 1
	sub $t1,$t1,1
	sw $t1, array($t0)	
	j ground
	
ground: 
	sub $t0, $t0, 4		
	j up
						
print:		
	li $v0,4
	la $a0,str2
	syscall					
													
	li $t0, 0
output:	
        beq $t0,-32,exit
	lw $a0, array($t0)	    
    	li $v0, 1			#Print arrray
    	syscall
    	li $v0, 11 			
    	li $a0, ' '	 
    	syscall
    	sub $t0,$t0,4	
	j output
	
	
exit:	li $v0,10
    	syscall

inputstring:				#procedure of inputstring
	la $a0,stringinput
	addi $a1,$0,10000
	li $v0,8
	syscall
	
	li $s1,0
	li $t2,0
	lb $t1,stringinput($t2)
	beq $t1,10,false
	beq $t1,45,negative
	
loopinput:	
	lb $t1,stringinput($t2)
	beq $t1,10,endinput
	
	sub $t1,$t1,48
	li $s4,-1
	slt $s5,$t1,$s4
	beq $s5,1,false
	li $s4,10
	slt $s5,$s4,$t1
	beq $s5,1,false
	
	mul $s1,$s1,10
	add $s1,$s1,$t1
	addi $t2,$t2,1
	j loopinput

false:	
	li $v0, 4
	la $a0, str4
	syscall
	
	j inputstring
negative:
	addi $t2,$t2,1
	lb $t1,stringinput($t2)
	sub $t1,$t1,48
	li $s4,-1
	slt $s5,$t1,$s4
	beq $s5,1,false
	li $s4,10
	slt $s5,$s4,$t1
	beq $s5,1,false
loopnegative:	
	lb $t1,stringinput($t2)
	beq $t1,10,endnegative
	
	sub $t1,$t1,48
	li $s4,-1
	slt $s5,$t1,$s4
	beq $s5,1,false
	li $s4,10
	slt $s5,$s4,$t1
	beq $s5,1,false
	
	mul $s1,$s1,10
	add $s1,$s1,$t1
	addi $t2,$t2,1
	j loopnegative
endnegative:
	mul $s1,$s1,-1	
	jr $ra
endinput:	
	jr $ra

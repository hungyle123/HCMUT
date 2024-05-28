.data
    array:.space 60       #4*15 bytes
    cout:.asciiz "Enter the 15 Elements :\n"
    str1:.asciiz "The array does not have the second largest number due to 15 elements have the same value."
    str2:.asciiz "Second largest value is "
    str3:.asciiz ", found in index "
    str4:.asciiz ", "
    str5:.asciiz "."
    str6: .asciiz "Please enter the element at index "
    str7: .asciiz ":"
    stringinput: .space 10000
    strinput: .asciiz "You input a invalid number. Please input again the recent value :"
.text   
	la $a0, cout
	li $v0,4
	syscall
	
	li $t0, 0
	li $t3, 0
input:	beq $t0,60,checkifhavesecond  	
    	
    	li $v0,4
   	la $a0,str6
   	syscall
   	
   	li $v0,1
   	move $a0,$t3
   	syscall
   	
   	li $v0,4
   	la $a0,str7
   	syscall
    	
    	
    	jal inputstring			#call procedure for inputstring
    	
   	sw $s1,array($t0)		#Store array
        addi $t0,$t0,4	
        addi $t3,$t3,1	
   	j input	

checkifhavesecond:			#This phase we check if the array have to same 15 element or not
	li $s0,0
	li $t0,0
	
	lw $s1,array($t0)
loop:	
	beq $t0,60,check
	lw $s2,array($t0)		
	bne $s1 ,$s2, increaseloop
	addi $s0,$s0,1
	
increaseloop:
	addi $t0,$t0,4
	j loop

check:
	bne $s0,15,yes			#if it get different than 15 so it exist second largest value

	li $v0,4
	la $a0,str1
	syscall
	
	li $v0,10
	syscall
	
yes:
	li $t0,0			#start to find a maximum value
	lw $s0,array($t0)
	addi $t0,$t0,4	
	
getmax:
	beq $t0,60,erasemax
	lw $s1,array($t0)
	slt $t1,$s0,$s1
	
	beq $t1,$0, next
	move $s0,$s1			#$s0 store the maximum value
next:
	addi $t0,$t0,4
	j getmax
	
erasemax:				#We set new value to the maximum value to the very negative one
	li $t0,0
	
looperase:
	beq $t0,60, getmax2
	lw $s1,array($t0)
	
	bne $s0,$s1, next1
	li $s1, -100000
	sw $s1,array($t0)
	
next1:
	addi $t0,$t0,4
	j looperase
	
getmax2:				#find max 1 more time and this time it is the second largest
	li $t0,0
	lw $s0, array($t0)
	addi $t0,$t0,4
loopgetmax2:	
	beq $t0,60,print
	lw $s1,array($t0)
	
	slt $t1,$s0,$s1
	
	beq $t1,$0,next2
	move $s0,$s1

next2:
	addi $t0,$t0,4
	j loopgetmax2
	
print:
	li $v0,4
	la $a0,str2
	syscall
	
	li $v0,1
	move $a0,$s0
	syscall
	
	li $v0,4
	la $a0,str3
	syscall
	
	li $s6,1			#boolean $s6 for the first print
	li $t0,0
loopprint:	
	beq $t0,15,end
	sll $t1,$t0,2
	lw $s1,array($t1)
	
	bne $s1,$s0,next3
	
	bne $s6,$0,first
	
	li $v0,4
	la $a0, str4
	syscall
	j printindex
	
first:
	li $s6,0
printindex:
	li $v0,1
	move $a0,$t0
	syscall
	
next3:
	addi $t0,$t0,1
	j loopprint
	
end:
	li $v0,10
	syscall

inputstring:				#procedure calling for input
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
	la $a0, strinput
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

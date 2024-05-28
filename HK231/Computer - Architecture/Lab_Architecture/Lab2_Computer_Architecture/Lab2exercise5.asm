.data
	array: .space 40
	value: .space 40
	number: .space 40
	str1: .asciiz "Unique values: "
	str2: .asciiz ", "
	str3: .asciiz ". "
	str4: .asciiz "Duplicated value: "
	str5: .asciiz ", repeated "
	str6: .asciiz " times"
	str7: .asciiz "; "
	cout:.asciiz "Enter the 10 Elements :\n"
	str8:.asciiz "The array does not have any unique value"
	str9: .asciiz "The array does not have any duplicate value"
	str10:.asciiz "."
	stringinput: .space 10000
   	strinput: .asciiz "You input a invalid number. Please input again the recent value :"
   	str11: .asciiz "Please enter the element "
   	str12: .asciiz ":"
.text
	la $a0, cout
	li $v0,4
	syscall
	
	li $s6,0		#store the number of different value
	
	li $t0, 0
	li $t3,1
input:	beq $t0,40, printunique	
    	
    	li $v0,4
   	la $a0,str11
   	syscall
   	
   	li $v0,1
   	move $a0,$t3
   	syscall
   	
   	li $v0,4
   	la $a0,str12
   	syscall
    	
    	jal inputstring
    	
   	sw $s1,array($t0)		#Store array
        
        li $t1,0
loop:    			#We start to check if the element is new or not
        bne $t1,$s6,next	
        sll $t2,$s6,2		#if new create a new element and increase
        sw $s1,value($t2)
        lw $s3, number($t2)
        addi $s3,$s3,1
        sw $s3,number($t2)
        addi $s6,$s6,1		
        j continue
next:
	sll $t2,$t1,2		#if it have already value plus 1 to the number freaquency array and go to continue
	lw $s3,value($t2)
	bne $s1,$s3,next1
        lw $s2, number($t2)
        addi $s2,$s2,1
        sw $s2, number($t2)
        j continue

next1:
	addi $t1,$t1,1
	j loop     
        
continue:       
        addi $t0,$t0,4	
        addi $t3,$t3,1	
   	j input	
printunique:
	sll $s4,$s6,2
	li $t0,0		
	li $s0,0			#check if have unique 
loopcheckunique:	
	beq $t0,$s4,stop
	
	lw $s3,number($t0)
	bne $s3,1,pass
	addi $s0,$s0,1
pass:
	addi $t0,$t0,4
	j loopcheckunique
	
stop:
	bne $s0,0,haveunique
	li $v0,4
	la $a0,str8
	syscall
	j endunique
	
haveunique:

	li $s7,1			#boolean $s7 for the first print
	li $v0,4
	la $a0,str1	
	syscall
	
	li $t0,0
loopunique:
	beq $t0,$s4,endunique
	lw $s3,number($t0)
	bne $s3,1,continueunique
	
	bne $s7,0,firstunique
	li $v0,4
	la $a0,str2
	syscall
	
firstunique:
	li $s7,0
	
	li $v0,1
	lw $s2,value($t0)
	move $a0,$s2
	syscall

continueunique:	
	addi $t0,$t0,4
	j loopunique
	
endunique:
	li $v0,4
	la $a0,str3
	syscall
	
	li $s0,0
	li $t0,0	
loopcheckduplicate:			#check if have duplicate or not
	beq $t0,$s4,stop1
	
	lw $s3,number($t0)
	beq $s3,1,pass1
	addi $s0,$s0,1
pass1:
	addi $t0,$t0,4
	j loopcheckduplicate
stop1:
	bne $s0,0,haveduplicate
	li $v0,4
	la $a0,str9
	syscall
	j endduplicate
	
haveduplicate:

	li $s7,1			#boolean $s7 for the first print
	li $v0,4
	la $a0,str4	
	syscall

	li $t0,0
loopduplicate:
	beq $t0,$s4,endduplicate
	lw $s3,number($t0)
	beq $s3,1,continueduplicate
	
	bne $s7,0,firstduplicate
	li $v0,4
	la $a0,str7
	syscall
	
firstduplicate:
	li $s7,0
	
	li $v0,1
	lw $s2,value($t0)
	move $a0,$s2
	syscall

	li $v0,4
	la $a0,str5
	syscall
	
	li $v0,1
	lw $s2,number($t0)
	move $a0,$s2
	syscall
	
	li $v0,4
	la $a0,str6
	syscall


continueduplicate:	
	addi $t0,$t0,4
	j loopduplicate
	
endduplicate:
	li $v0,4
	la $a0, str10
	syscall
	
	li $v0,10
	syscall


inputstring:					#procedure calling
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

.data
	setsizeA: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	
	setsizeB: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	
	printA: .word  	32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
	
	printB: .word   32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
	numberA: .word 16
	numberB: .word 16
	inputstring: .space 10000
	
	filename: .asciiz "Assignmentoutput.txt"
	save: .word 0
	decorate: .asciiz "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
	str:  .asciiz "                                                                             WELCOME TO THE BATTLE-SHIP GAME !!!                                                                    "
	rule: .asciiz "PLEASE NOTICE:\n"
	rule0: .asciiz "0.IN THIS PROGRAM I DENOTE R FOR \"ROW\" , C DENOTE FOR \"COLUMN\" \n"
	rule1: .asciiz "1.WHEN INPUT A SHIP COORDINATE. PLEASE INPUT A BOW AND STERN OF SHIP IN 1 LINE: \"R1 C1 R2 C2\"\n"
	rule2: .asciiz "(IF YOU INPUT WRONG AS THE RULE. THE PROGRAM WILL TELL YOU TO INPUT AGAIN !!!)\n"
	rule3: .asciiz "2.WHEN INPUT A COORDINATE TO SHOOT. PLEASE INPUT ROW AND COLUMN IN 1 LINE: \"R C\"\n"
	example: .asciiz "EXAMPLE:Input bow and stern of the ship of size 4: \n"
	example1: .asciiz "0 0 0 3 (R1 = 0, C1 = 0, R2 = 0, C2 = 3 is an example of valid input)\n"
	example2: .asciiz "EXAMPLE:Input the coordinate to shoot: \n"
	example3: .asciiz "0 0 (R = 0, C = 0 is an example of valid input)\n"
	
	strA: .asciiz "PLAYER A TURN TO SET THE SHIP!\n"
	strB: .asciiz "PLAYER B TURN TO SET THE SHIP:\n"
	rowcolumn: .asciiz "R1 C1 R2 C2\n"
	
	str1: .asciiz "Please input the bow and stern coordinate of the ship of size 4: \n"
	str2: .asciiz "Please input the bow and stern coordinate of the first ship of size 3: \n"
	str3: .asciiz "Please input the bow and stern coordinate of the second ship of size 3: \n"
	str4: .asciiz "Please input the bow and stern coordinate of the first ship of size 2: \n"
	str5: .asciiz "Please input the bow and stern coordinate of the second ship of size 2: \n"
	str6: .asciiz "Please input the bow and stern coordinate of the third ship of size 2: \n"
	str7: .asciiz "You has just input an overlap ship. Please input again!\n"
	str8: .asciiz "You has just input an invalid coordinate. The valid coordinate is from 0 to 6. Please input again! \n"
	str9: .asciiz "You has just input a diagonal line. Please input again!\n"
	str10: .asciiz "You has just input an invalid coordinate. The valid coordinate is from 0 to 6. Please input again! \n"
	
	strA1: .asciiz "Player A has input the bow and stern coordinate of the ship of size 4:"
	strA2: .asciiz "Player A has input the bow and stern coordinate of the first ship of size 3:"
	strA3: .asciiz "Player A has input the bow and stern coordinate of the second ship of size 3:"
	strA4: .asciiz "Player A has input the bow and stern coordinate of the first ship of size 2:"
	strA5: .asciiz "Player A has input the bow and stern coordinate of the second ship of size 2:"
	strA6: .asciiz "Player A has input the bow and stern coordinate of the third ship of size 2:"
	
	strB1: .asciiz "Player B has input the bow and stern coordinate of the ship of size 4:"
	strB2: .asciiz "Player B has input the bow and stern coordinate of the first ship of size 3:"
	strB3: .asciiz "Player B has input the bow and stern coordinate of the second ship of size 3:"
	strB4: .asciiz "Player B has input the bow and stern coordinate of the first ship of size 2:"
	strB5: .asciiz "Player B has input the bow and stern coordinate of the second ship of size 2:"
	strB6: .asciiz "Player B has input the bow and stern coordinate of the third ship of size 2:"
	
	strAshooting: .asciiz "Player A has input coordinate to shoot:"
	strBshooting: .asciiz "Player B has input coordinate to shoot:"
	num0: .asciiz "0"
	num1: .asciiz "1"
	num2: .asciiz "2"
	num3: .asciiz "3"
	num4: .asciiz "4"
	num5: .asciiz "5"
	num6: .asciiz "6"
	num7: .asciiz "O"
	num8: .asciiz "X"
	num9: .asciiz " "
	
	size: .asciiz "You has just input a "
	size1: .asciiz "-size ship. The necessary size is "
	size2: .asciiz ". Please input again!\n"
	
	index: .asciiz "Index "
	space: .asciiz " "
	space1: .asciiz "  "
	space2:	.asciiz "   "
	space3: .asciiz"                                 "
	line: .asciiz  "                                       +---+---+---+---+---+---+---+\n"
	writefirst: .asciiz "|"
	writelast: .asciiz " |"
	
	enter: .asciiz "\n"
	Aturn: .asciiz "A TURN TO SHOOT B SHIP!!!!\n""
	Bturn: .asciiz "B TURN TO SHOOT A SHIP!!!!\n""
	coordinate: .asciiz "Please choose a coordinate to shoot:\n"
	already: .asciiz "You already shoot that cell. Please choose again a coordinate to shoot: \n"
	
	hit: .asciiz "HIT!!!\n"
	miss: .asciiz "MISS!!!\n"
	
	vicA: .asciiz "THE BATTLE SHIP GAME IS OVER! PLAYER A IS THE WINNER!!!!"
	vicB: .asciiz "THE BATTLE SHIP GAME IS OVER! PLAYER B IS THE WINNER!!!!"
.text
	# Open (for writing) a file that does not exist
  	li   $v0, 13       # system call for open file
  	la   $a0, filename     
  	li   $a1, 1       
 	li   $a2, 0        
 	syscall            
 	sw $v0, save   
	
#---------------------------------------------------------------#This phase we only print the INTRODUCTION OF THE BATTLE SHIP GAME-----------------------------------------------------------------------------------------------------------------------#
	li $v0,4
	la $a0,decorate						
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  188    
  	syscall   

	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall

	li $v0,4
	la $a0,str
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  180   
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,decorate
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  188    
  	syscall
#---------------------------------------------------------------------This phase we print and write to file THE RULE AND THE EXAMPLE OF PLAYING GAME--------------------------------------------------------------------------------------------------------------------#	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4					
	la $a0,rule
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  15  
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,rule0
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  64    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,rule1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  94   
  	syscall
	
	li $v0,4
	la $a0,rule2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  79    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,example
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  52    
  	syscall
	
	li $v0,4
	la $a0,example1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  70    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,rule3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  81   
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,example2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  40    
  	syscall
	
	li $v0,4
	la $a0,example3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  48    
  	syscall
	
	li $v0,4
	la $a0,decorate
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  188    
  	syscall
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0, strA
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  31    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	jal printsetsizeA
inputsize4A:
	
	li $v0,4
	la $a0, str1
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue1
	j inputsize4A
continue1:
	li $s7,4			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue2
	j inputsize4A
	
continue2:
	jal checkoverlapandfillA	
	beq $s5,1,inputsize4A
	
	li   $v0, 15
	la   $a1, strA1         
	lw $a0, save        
  	li   $a2,  70    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         	#after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
  	
  	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeA
inputsize3A1:
	
	li $v0,4
	la $a0, str2
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue3
	j inputsize3A1
continue3:
	li $s7,3			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue4
	j inputsize3A1
	
continue4:
	jal checkoverlapandfillA
	beq $s5,1,inputsize3A1
	
	li   $v0, 15
	la   $a1, strA2         
	lw $a0, save        
  	li   $a2,  76    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeA
inputsize3A2:
	
	li $v0,4
	la $a0, str3
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue5
	j inputsize3A2
continue5:
	li $s7,3			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue6
	j inputsize3A2
	
continue6:
	jal checkoverlapandfillA
	beq $s5,1,inputsize3A2
	
	li   $v0, 15
	la   $a1, strA3         
	lw $a0, save        
  	li   $a2,  77    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeA
inputsize2A1:
	
	li $v0,4
	la $a0, str4
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue7
	j inputsize2A1
continue7:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue8
	j inputsize2A1
	
continue8:
	jal checkoverlapandfillA
	beq $s5,1,inputsize2A1
	
	li   $v0, 15
	la   $a1, strA4         
	lw $a0, save        
  	li   $a2,  76    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	
	jal printsetsizeA
inputsize2A2:
	
	li $v0,4
	la $a0, str5
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue9
	j inputsize2A2
continue9:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue10
	j inputsize2A2
	
continue10:
	jal checkoverlapandfillA
	beq $s5,1,inputsize2A2
	
	li   $v0, 15
	la   $a1, strA5         
	lw $a0, save        
  	li   $a2,  77    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeA
inputsize2A3:
	
	li $v0,4
	la $a0, str6
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue11
	j inputsize2A3
continue11:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue12
	j inputsize2A3
	
continue12:
	jal checkoverlapandfillA
	beq $s5,1,inputsize2A3
	
	li   $v0, 15
	la   $a1, strA6         
	lw $a0, save        
  	li   $a2,  76    
  	syscall
	
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeA
	
	li $v0,4
	la $a0,strB
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  31    
  	syscall
	
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	jal printsetsizeB
inputsize4B:
	
	li $v0,4
	la $a0, str1
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue1B
	j inputsize4B
continue1B:
	li $s7,4			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue2B
	j inputsize4B
	
continue2B:
	jal checkoverlapandfillB	
	beq $s5,1,inputsize4B
	
	li   $v0, 15
	la   $a1, strB1         
	lw $a0, save        
  	li   $a2,  70    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall

	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
inputsize3B1:
	
	li $v0,4
	la $a0, str2
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue3B
	j inputsize3B1
continue3B:
	li $s7,3			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue4B
	j inputsize3B1
	
continue4B:
	jal checkoverlapandfillB
	beq $s5,1,inputsize3B1
	
	li   $v0, 15
	la   $a1, strB2         
	lw $a0, save        
  	li   $a2,  76    
  	syscall
	
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall

	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
inputsize3B2:
	
	li $v0,4
	la $a0, str3
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue5B
	j inputsize3B2
continue5B:
	li $s7,3			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue6B
	j inputsize3B2
	
continue6B:
	jal checkoverlapandfillB
	beq $s5,1,inputsize3B2
	
	li   $v0, 15
	la   $a1, strB3         
	lw $a0, save        
  	li   $a2,  77    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall

	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
inputsize2B1:
	
	li $v0,4
	la $a0, str4
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue7B
	j inputsize2B1
continue7B:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue8B
	j inputsize2B1
	
continue8B:
	jal checkoverlapandfillB
	beq $s5,1,inputsize2B1
	
	li   $v0, 15
	la   $a1, strB4         
	lw $a0, save        
  	li   $a2,  76   
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
inputsize2B2:
	
	li $v0,4
	la $a0, str5
	syscall
	

	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue9B
	j inputsize2B2
continue9B:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue10B
	j inputsize2B2
	
continue10B:
	jal checkoverlapandfillB
	beq $s5,1,inputsize2B2
	
	li   $v0, 15
	la   $a1, strB5         
	lw $a0, save        
  	li   $a2,  77    
  	syscall
	
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2, 7
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
inputsize2B3:
	
	li $v0,4
	la $a0, str6
	syscall
	
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	jal checkvalidcoordinate1
	jal checkvalidcoordinate2
	
	jal checkstraightline
	bne $t4,2,continue11B
	j inputsize2B3
continue11B:
	li $s7,2			#$s7 store the necessary size need to be checked
	jal checksizeship
	
	beq $s7,$s6,continue12B
	j inputsize2B3
	
continue12B:
	jal checkoverlapandfillB
	beq $s5,1,inputsize2B3
	
	li   $v0, 15
	la   $a1, strB6         
	lw $a0, save        
  	li   $a2,  76    
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         #after checking all valid thing we start to apply 1 to the table then print to terminal and write to file again
	lw $a0, save        
  	li   $a2,  7
  	syscall

	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	jal printsetsizeB
	

turnA:
	
	li $v0,4
	la $a0,Aturn
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 27
	syscall
	
	jal printshowB
	
	li $v0,4
	la $a0,coordinate
	syscall
reinputA:	
	la $a0,inputstring				#input the coordinate of the cell shooting
	addi $a1,$0,10000				
	li $v0,8					
	syscall
	
	jal checkvalidcoordinateshooting			
	

	mul $s5,$t6,28
	add $t1,$s5,$s0
	mul $s5,$t7,4
	add $t1,$t1,$s5
	
	lw $t2,setsizeB($t1)
	beq $t2,-1,alreadyA
	
	li   $v0, 15
	la   $a1, strAshooting         		#Write to file the turn each player shoot
	lw $a0, save        
  	li   $a2,  39
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         
	lw $a0, save        
  	li   $a2,  3
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	beq $t2,0,missA
	
	li $v0,4
	la $a0,hit
	syscall
	
	li   $v0, 15
	la   $a1, hit         			#if HIT then write to file
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	li $t2,-1
	sw $t2,setsizeB($t1)
	
	li $t3,88
	sw $t3,printB($t1)

	
	lw $t3,numberB($0)
	sub $t3,$t3,1
	sw $t3,numberB($0)
	beq $t3,0,Awin
	jal printshowB
	j turnB
	
alreadyA:
	li $v0,4
	la $a0,already
	syscall
	j reinputA
	
missA:
	li $v0,4
	la $a0,miss
	syscall
	
	li   $v0, 15
	la   $a1, miss        			#if MISS then write to file also
	lw $a0, save        
  	li   $a2,  8
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	li $t2,-1
	sw $t2,setsizeB($t1)
	
	li $t3,79
	sw $t3,printB($t1)
	
	jal printshowB				#print to terminal the table after shoot 
	j turnB

turnB:
	li $v0,4
	la $a0,Bturn
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 27
	syscall
	
	jal printshowA
	
	li $v0,4
	la $a0,coordinate
	syscall
reinputB:	
	la $a0,inputstring				#input the coordinate of the cell shooting
	addi $a1,$0,10000				
	li $v0,8					
	syscall
	
	jal checkvalidcoordinateshooting
	
	mul $s5,$t6,28
	add $t1,$s5,$s0
	mul $s5,$t7,4
	add $t1,$t1,$s5
	
	lw $t2,setsizeA($t1)
	beq $t2,-1,alreadyB
	
	li   $v0, 15
	la   $a1, strAshooting         			#Write to file the turn each player shoot
	lw $a0, save        
  	li   $a2,  39
  	syscall
	
	li   $v0, 15
	la   $a1, inputstring         
	lw $a0, save        
  	li   $a2,  3
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	beq $t2,0,missB
	
	li $v0,4
	la $a0,hit							#if HIT then write to file
	syscall
	
	li   $v0, 15
	la   $a1, hit         
	lw $a0, save        
  	li   $a2,  7
  	syscall
	
	
	li $t2,-1
	sw $t2,setsizeA($t1)
	
	li $t3,88
	sw $t3,printA($t1)
	
	
	lw $t3,numberA($0)
	sub $t3,$t3,1
	sw $t3,numberA($0)
	beq $t3,0,Bwin
	jal printshowA
	j turnA
	
alreadyB:
	li $v0,4
	la $a0,already
	syscall
	
	j reinputB
	
missB:
	li $v0,4
	la $a0,miss
	syscall
	
	li   $v0, 15
	la   $a1, miss        					#if MISS then write to file also
	lw $a0, save        
  	li   $a2,  8
  	syscall
	
	li   $v0, 15
	la   $a1, enter         
	lw $a0, save        
  	li   $a2,  1
  	syscall
	
	li $t2,-1
	sw $t2,setsizeA($t1)
	
	li $t3,79
	sw $t3,printA($t1)
	
	jal printshowA
	j turnA
	
Awin:
	jal printshowB

	li $v0,4
	la $a0,vicA
	syscall
	
	li   $v0, 15
	la   $a1, vicA         
	lw $a0, save        
  	li   $a2,  56
  	syscall
	
	li   $v0, 16       # system call for close file
  	lw $a0, save      # file descriptor to close
  	syscall
	
	li $v0,10
	syscall
	
Bwin:
	jal printshowA
	
	li $v0,4
	la $a0,vicB
	syscall
	
	li   $v0, 15
	la   $a1, vicB         
	lw $a0, save        
  	li   $a2,  56
  	syscall
	
	li   $v0, 16       # system call for close file
  	lw $a0, save      # file descriptor to close
  	syscall
	
	li $v0,10
	syscall
#********************************************PROCEDURE TO CHECK VALID COORDINATE TO SETSIZE SHIP****************************************************************************************************************#		
checkvalidcoordinate1:
	li $t3,1
	lb $t6,inputstring($t3)
	bne $t6,32,reinputvalidcoordinate1
	
	li $t3,3
	lb $t6,inputstring($t3)
	bne $t6,32,reinputvalidcoordinate1
	
	li $t3,0
	lb $t6,inputstring($t3)
	sub $t6,$t6,48
	
	li $t3,2
	lb $t7,inputstring($t3)
	sub $t7,$t7,48						#We start to check each byte value to see if the input is valid or not
	
	slti $t5,$t6,-1
	beq $t5,1,reinputvalidcoordinate1
	
	slti $t5,$t7,-1
	beq $t5,1,reinputvalidcoordinate1
	
	li $t4,6
	slt $t5,$t4,$t6
	beq $t5,1,reinputvalidcoordinate1
	slt $t5,$t4,$t7
	beq $t5,1,reinputvalidcoordinate1
	jr $ra

reinputvalidcoordinate1:					#if we find that the coordinate is not valid we start to tell the player to input again
	li $v0,4
	la $a0,str8
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	j checkvalidcoordinate1

checkvalidcoordinate2:
	li $t3,5
	lb $t8,inputstring($t3)
	bne $t8,32,reinputvalidcoordinate2
	
	li $t3,7
	lb $t9,inputstring($t3)
	bne $t9,10,reinputvalidcoordinate2
	
	li $t3,4
	lb $t8,inputstring($t3)
	sub $t8,$t8,48
									#We start to check each byte value to see if the input is valid or not
	li $t3,6
	lb $t9,inputstring($t3)
	sub $t9,$t9,48
	
	slti $t5,$t8,-1
	beq $t5,1,reinputvalidcoordinate2
	
	slti $t5,$t9,-1
	beq $t5,1,reinputvalidcoordinate2
	
	li $t4,6
	slt $t5,$t4,$t8
	beq $t5,1,reinputvalidcoordinate2
	slt $t5,$t4,$t9
	beq $t5,1,reinputvalidcoordinate2
	jr $ra

reinputvalidcoordinate2:
	li $v0,4
	la $a0,str8					#if we find that the coordinate is not valid we start to tell the player to input again
	syscall
	
	la $a0,inputstring				#input the bow and stern of the boat
	addi $a1,$0,10000				# $t6 $t7 store the bow
	li $v0,8					# $t8 $t9 store the stern
	syscall
	
	j checkvalidcoordinate1
checkstraightline:						#check if the input is straight or not
	li $t4,0
	beq $t6,$t8,checkline1
	addi $t4,$t4,1
checkline1:
	beq $t7,$t9,checkline2
	addi $t4,$t4,1
checkline2:
	bne $t4,2,checkline3
	
	li $v0,4
	la $a0,str9
	syscall
	
checkline3:
	jr $ra
#********************************************PROCEDURE TO CHECK SIZE SHIP****************************************************************************************************************#
checksizeship:					
	beq $t6,$t8,elsechecksizeship			#check size of a row ship
	sub $s6,$t6,$t8
	slti $t5,$s6,0
	bne $t5,1,nextchecksize1			#we start to make sure $s6 > 0
	sub $s6,$0,$s6
nextchecksize1:
	addi $s6,$s6,1
	beq $s7,$s6,endchecksize1			#if it exactly the size we want go back to the main flow
	
	li $v0,4
	la $a0,size
	syscall
	
	li $v0,1					#if not back to the main flow with $s7 different and then reinput
	move $a0,$s6
	syscall
	
	li $v0,4
	la $a0,size1
	syscall
	
	li $v0,1
	move $a0,$s7
	syscall
	
	li $v0,4
	la $a0,size2
	syscall
endchecksize1:
	jr $ra
	
elsechecksizeship:					#check size of a colimn ship
	sub $s6,$t7,$t9					
	slti $t5,$s6,0
	bne $t5,1,nextchecksize2
	sub $s6,$0,$s6					#we start to make sure $s6 > 0
nextchecksize2:
	addi $s6,$s6,1
	beq $s7,$s6,endchecksize2			#if it exactly the size we want go back to the main flow
	
	li $v0,4
	la $a0,size
	syscall
							#if not back to the main flow with $s7 different and then reinput
	li $v0,1
	move $a0,$s6
	syscall
	
	li $v0,4
	la $a0,size1
	syscall
	
	li $v0,1
	move $a0,$s7
	syscall
	
	li $v0,4
	la $a0,size2
	syscall
endchecksize2:
	jr $ra
#********************************************PROCEDURE TO CHECK OVERLAP OR NOT AND IF IT NOT OVERLAP THEN FILL 1 TO THE TABLE****************************************************************************************************************#
printsetsizeA:
	li $v0,4
	la $a0,space3
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall

	li $v0,4
	la $a0,index
	syscall
	
	li $t0,0						#this phase we just tab a space for a more clearly table
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  6    
  	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
  	
rowindexsetsizeA:
	li $v0,4
	la $a0,space
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,1
	move $a0,$t0
	syscall						# INDEX      0     1     2      3       4        5         6
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2    
  	syscall
  	
	addi $t0,$t0,1
	beq $t0,7,endindexsetsizeA
	j rowindexsetsizeA
endindexsetsizeA:
	li $v0,4
	la $a0,enter
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall 

	li $t2,0
	li $t1,0
	li $v0,4					#Print the rest of the table also with the line
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69   
  	syscall
	
	li $t0,0
firstsetsizeAloop:
	addi $t2,$t2,28
	li $v0,4
	la $a0,space3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la   $a1,  num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,space2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  3
	syscall
	
	li $v0,4
	la $a0,writefirst
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1 
  	syscall  
secondsetsizeAloop:
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,1
	lw $a0,setsizeA($t1)
	syscall
	
	lw $s3,setsizeA($t1)
	mul $s3,$s3,2
	
	li   $v0, 15
	la  $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,writelast
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 2	
	syscall	
				
	addi $t1,$t1,4
	beq $t1,$t2,endsecondsetsizeAloop
	j secondsetsizeAloop
endsecondsetsizeAloop:
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69
	syscall
	
	addi $t0,$t0,1
	beq $t0,7,endfirstsetsizeAloop
	j firstsetsizeAloop
endfirstsetsizeAloop:
	jr $ra
#********************************************PROCEDURE TO CHECK OVERLAP OR NOT AND IF IT NOT OVERLAP THEN FILL 1 TO THE TABLE A****************************************************************************************************************#	
checkoverlapandfillA:
	beq $t6 ,$t8,columncheckA
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapcheckoverlap1				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapcheckoverlap1:
	addi $s7,$s7,28
	
loopoverlapcheck1:
	
	lw $s5,setsizeA($s6)					#get the value and check if is already 1 then jump to the overlap
	beq $s5,1,overlapA
	addi $s6,$s6,28
	beq $s6,$s7,endoverlapcheck1
	j loopoverlapcheck1

endoverlapcheck1:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapfillA1				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapfillA1:
	addi $s7,$s7,28						
	
loopfillA1:
	li $s5,1
	sw $s5,setsizeA($s6)				#fill 1 to the table
	addi $s6,$s6,28
	beq $s6,$s7,endfillA
	j loopfillA1
	
columncheckA:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapcheckoverlap2				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapcheckoverlap2:
	addi $s7,$s7,4
	
loopoverlapcheck2:
	
	lw $s5,setsizeA($s6)					#get the value and check if is already 1 then jump to the overlap
	beq $s5,1,overlapA
	addi $s6,$s6,4
	beq $s6,$s7,endoverlapcheck2
	j loopoverlapcheck2

endoverlapcheck2:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapfillA2				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapfillA2:
	addi $s7,$s7,4
	
loopfillA2:
	li $s5,1
	sw $s5,setsizeA($s6)				#fill 1 to the table
	addi $s6,$s6,4	
	beq $s6,$s7,endfillA
	j loopfillA2
overlapA:
	li $v0,4
	la $a0,str7
	syscall
	
	li $s5,1
	jr $ra
	
endfillA:
	li $s5,0
	jr $ra


#********************************************PRINT THE SETSIZE TABLE B TO THE TERMINAL****************************************************************************************************************#
printsetsizeB:
	li $v0,4
	la $a0,space3
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall

	li $v0,4
	la $a0,index
	syscall
	
	li $t0,0					#this phase we just tab a space for a more clearly table

	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  6    
  	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall


rowindexsetsizeB:
	li $v0,4
	la $a0,space
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,1
	move $a0,$t0
	syscall							# INDEX      0     1     2      3       4        5         6

	
	mul $s3,$t0,2
	
	li   $v0, 15
	la $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2    
  	syscall


	addi $t0,$t0,1
	beq $t0,7,endindexsetsizeB
	j rowindexsetsizeB
endindexsetsizeB:
	li $v0,4
	la $a0,enter
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall 

	li $t2,0
	li $t1,0
	li $v0,4
	la $a0,enter					#Print the rest of the table also with the line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69   
  	syscall
	
	li $t0,0

firstsetsizeBloop:
	addi $t2,$t2,28
	li $v0,4
	la $a0,space3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la   $a1,  num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,space2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  3
	syscall
	
	li $v0,4
	la $a0,writefirst
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1 
  	syscall

	
secondsetsizeBloop:
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,1
	lw $a0,setsizeB($t1)
	syscall
	
	lw $s3,setsizeB($t1)
	mul $s3,$s3,2
	
	li   $v0, 15
	la  $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,writelast
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 2	
	syscall

	
	addi $t1,$t1,4
	beq $t1,$t2,endsecondsetsizeBloop
	j secondsetsizeBloop
endsecondsetsizeBloop:
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69
	syscall

	
	addi $t0,$t0,1
	beq $t0,7,endfirstsetsizeBloop
	j firstsetsizeBloop
endfirstsetsizeBloop:
	jr $ra

#********************************************PROCEDURE TO CHECK OVERLAP OR NOT AND IF IT NOT OVERLAP THEN FILL 1 TO THE TABLE B****************************************************************************************************************#
checkoverlapandfillB:
	beq $t6 ,$t8,columncheckB
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapcheckoverlap1B				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapcheckoverlap1B:
	addi $s7,$s7,28
	
loopoverlapcheck1B:
	
	lw $s5,setsizeB($s6)					#get the value and check if is already 1 then jump to the overlap
	beq $s5,1,overlapB
	addi $s6,$s6,28
	beq $s6,$s7,endoverlapcheck1B
	j loopoverlapcheck1B

endoverlapcheck1B:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapfillB1				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapfillB1:
	addi $s7,$s7,28
	
loopfillB1:
	li $s5,1
	sw $s5,setsizeB($s6)				#fill 1 to the table
	addi $s6,$s6,28
	beq $s6,$s7,endfillB
	j loopfillB1
	
columncheckB:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapcheckoverlap2B				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapcheckoverlap2B:
	addi $s7,$s7,4
		
loopoverlapcheck2B:
	
	lw $s5,setsizeB($s6)					#get the value and check if is already 1 then jump to the overlap
	beq $s5,1,overlapB
	addi $s6,$s6,4
	beq $s6,$s7,endoverlapcheck2B
	j loopoverlapcheck2B

endoverlapcheck2B:
	mul $s6,$t6,28
	mul $s5,$t7,4
	add $s6,$s6,$s5
	mul $s7,$t8,28
	mul $s5,$t9,4
	add $s7,$s7,$s5
	slt $s5,$s6,$s7
	beq $s5,1,notswapfillB2				#incase $s6 > $s7 we need to swap 2 value
	add $s6,$s6,$s7
	sub $s7,$s6,$s7
	sub $s6,$s6,$s7
	
notswapfillB2:
	addi $s7,$s7,4
	
loopfillB2:
	li $s5,1
	sw $s5,setsizeB($s6)					#fill 1 to the table
	addi $s6,$s6,4
	beq $s6,$s7,endfillB
	j loopfillB2
overlapB:
	li $v0,4
	la $a0,str7
	syscall
	
	li $s5,1
	jr $ra
	
endfillB:
	li $s5,0
	jr $ra
#********************************************PRINT THE TABLE A TO THE TERMINAL****************************************************************************************************************#	
printshowA:
	li $v0,4
	la $a0,space3
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall

	li $v0,4
	la $a0,index
	syscall
	
	li $t0,0					#this phase we just tab a space for a more clearly table
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  6    
  	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall


rowindexshowA:
	li $v0,4
	la $a0,space
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1    
  	syscall						# INDEX      0     1     2      3       4        5         6
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2    
  	syscall

	addi $t0,$t0,1

	beq $t0,7,endindexshowA
	j rowindexshowA
endindexshowA:
	li $v0,4
	la $a0,enter
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall 

	li $t2,0
	li $t1,0
	
	li $v0,4
	la $a0,enter						#Print the rest of the table also with the line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69   
  	syscall
	
	li $t0,0


firstshowAloop:
	addi $t2,$t2,28
	li $v0,4
	la $a0,space3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la   $a1,  num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,space2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  3
	syscall
	
	li $v0,4
	la $a0,writefirst
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1 
  	syscall 
	
secondshowAloop:
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,11
	lw $a0,printA($t1)
	syscall
	
	beq $a0,79,vector1						#change to number $a0 to the exact offset 
	beq $a0,88,vector2	
	li $a0,9
	j endvector1

vector1:				
 	li $a0,7
 	j endvector1
vector2:
	li $a0,8
	j endvector1
endvector1:
	mul $a0,$a0,2	
	li   $v0, 15
	la  $a1,num0($a0)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,writelast
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 2	
	syscall

	
	addi $t1,$t1,4
	beq $t1,$t2,endsecondshowAloop
	j secondshowAloop
endsecondshowAloop:
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69
	syscall
	
	addi $t0,$t0,1
	beq $t0,7,endfirstshowAloop
	j firstshowAloop
endfirstshowAloop:
	jr $ra
#********************************************PRINT THE TABLE B TO THE TERMINAL****************************************************************************************************************#	
printshowB:
	li $v0,4
	la $a0,space3
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall

	li $v0,4
	la $a0,index
	syscall
	
	li $t0,0					#this phase we just tab a space for a more clearly table
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  6    
  	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall


rowindexshowB:
	li $v0,4
	la $a0,space
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la $a1,num0($s3)         
	lw $a0, save        
  	li   $a2,  1    
  	syscall					# INDEX      0     1     2      3       4        5         6	
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2    
  	syscall

	addi $t0,$t0,1
	beq $t0,7,endindexshowB
	j rowindexshowB
endindexshowB:
	li $v0,4
	la $a0,enter
	syscall

	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall 

	li $t2,0
	li $t1,0
	li $v0,4
	la $a0,enter						#Print the rest of the table also with the line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1    
  	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69   
  	syscall
	
	li $t0,0


firstshowBloop:
	addi $t2,$t2,28
	li $v0,4
	la $a0,space3
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  33    
  	syscall
	
	li $v0,4
	la $a0,space1
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  2
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	mul $s3,$t0,2
	
	li   $v0, 15
	la   $a1,  num0($s3)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,space2
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  3
	syscall
	
	li $v0,4
	la $a0,writefirst
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1 
  	syscall

	
secondshowBloop:
	li $v0,4
	la $a0,space
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,11
	lw $a0,printB($t1)
	syscall
	
	beq $a0,79,vector3						#change to number $a0 to the exact offset
	beq $a0,88,vector4
	li $a0,9
	j endvector3			

vector3:
 	li $a0,7
 	j endvector3
vector4:
	li $a0,8
	j endvector3
endvector3:
	mul $a0,$a0,2
	li   $v0, 15
	la  $a1,num0($a0)         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,writelast
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2, 2	
	syscall

	
	addi $t1,$t1,4
	beq $t1,$t2,endsecondshowBloop
	j secondshowBloop
endsecondshowBloop:
	li $v0,4
	la $a0,enter
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  1
	syscall
	
	li $v0,4
	la $a0,line
	syscall
	
	li   $v0, 15
	move   $a1, $a0         
	lw $a0, save        
  	li   $a2,  69
	syscall

	
	addi $t0,$t0,1

	beq $t0,7,endfirstshowBloop
	j firstshowBloop
endfirstshowBloop:
	jr $ra

#********************************************PROCEDURE FOR CHECKING VALID COORDINATE SHOOTING****************************************************************************************************#
checkvalidcoordinateshooting:
	li $t3,1
	lb $t6,inputstring($t3)
	bne $t6,32,reinputvalidcoordinateshooting				#check the type input 		
	
	li $t3,3
	lb $t6,inputstring($t3)
	bne $t6,10,reinputvalidcoordinateshooting
	
	li $t3,0
	lb $t6,inputstring($t3)
	sub $t6,$t6,48
	
	li $t3,2
	lb $t7,inputstring($t3)
	sub $t7,$t7,48
	
	slti $t5,$t6,-1
	beq $t5,1,reinputvalidcoordinateshooting
	
	slti $t5,$t7,-1
	beq $t5,1,reinputvalidcoordinateshooting
	
	li $t4,6
	slt $t5,$t4,$t6
	beq $t5,1,reinputvalidcoordinateshooting
	slt $t5,$t4,$t7
	beq $t5,1,reinputvalidcoordinateshooting
	jr $ra

reinputvalidcoordinateshooting:				#if input invalid then print to terminal and tell the player to reinput
	li $v0,4
	la $a0,str10
	syscall
	
	la $a0,inputstring				
	addi $a1,$0,10000				
	li $v0,8					
	syscall
	
	j checkvalidcoordinateshooting

#**************************************************************************************END PROGRAM*****************************************************************************************************#

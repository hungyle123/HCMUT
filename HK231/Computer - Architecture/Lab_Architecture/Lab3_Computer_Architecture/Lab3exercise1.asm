.data
	mode: .asciiz "Choose mode: 1. Volume; 2. Total surface area; 3. Print all Volume and total surface area\n"
	error: .asciiz "No. You have to input a number 1, 2 or 3!\n"
	metric: .asciiz "Choose metric: 1. cm; 2. dm; 3. m; 4. inche\n"
	error1:.asciiz "No. You have to input a number from 1 to 4!\n"
	error2:.asciiz "No. You have to input a number from 1 to 4!\n"
	error3: .asciiz "No. You have to input a number from 1 to 2!\n"
	shape: .asciiz "Please choose shape you want to calculate: 1 .Rectangle box; 2 .Cube; 3. Cylinder; 4. Rectangular Pyramid\n"
	input1: .asciiz "Please input the length of edge a: "
	input2: .asciiz "Please input the length of edge b: "
	input3: .asciiz "Please input the length of edge c: "
	input_cube: .asciiz "Please input the length of 1 edge of cube: " 
	input_height_cylinder: .asciiz "Please input the height of cylinder: " 
	input_radius_cylinder: .asciiz "Please input the radius of the bottom circle of cylinder: "
	input_height_pyramid: .asciiz "Please input the height of pyramid: " 
	input_edgea_pyramid: .asciiz "Please input the length of edge a of bottom rectangle of pyramid: " 
	input_edgeb_pyramid: .asciiz "Please input the length of edge b of bottom rectangle of pyramid: " 
	
	negative: .asciiz "The input must be positve\n"
	enter: .asciiz "\n"
	volume: .asciiz "The volume of "
	area: .asciiz "The total surface area of "
	rectangle: .asciiz "rectangle box is: "
	cube: .asciiz "cube is: "
	cylinder: .asciiz "cylinder is: "
	pyramid: .asciiz "rectangular pyramid is: "
	cm2: .asciiz " cm^2 \n"
	dm2: .asciiz " dm^2 \n"
	m2: .asciiz " m^2 \n"
	inche2: .asciiz " inche^2 \n"
	cm3: .asciiz " cm^3 \n"
	dm3: .asciiz " dm^3 \n"
	m3: .asciiz " m^3 \n"
	inche3: .asciiz " inche^3 \n"
	pi_double: .double 3.141592654
	double_3: .double 3.0
	double_2: .double 2.0
	double_4: .double 4.0
	double_6: .double 6.0
	double_0433: .double 0.433
.text
choosemode:
	li $v0,4 
	la $a0,mode				#first choose mode to calculate
	syscall
	
	li $v0,5
	syscall
	move $s7, $v0
	
	bge $s7,1,continue1			#check if error input
	li $v0,4 				
	la $a0,error
	syscall
	j choosemode
continue1:
	
	blt $s7,4,continue2
	li $v0,4 
	la $a0,error				#check if error input
	syscall
	j choosemode
continue2:
	li $v0,4 
	la $a0,metric				#ask the user which metric to use
	syscall
	
	li $v0,5
	syscall
	move $s6, $v0
	
	bge $s6,1,continue3
	li $v0,4 
	la $a0,error1				#check if error input
	syscall
	j continue2
continue3:
	
	blt $s6,5,continue4
	li $v0,4 
	la $a0,error1				#check if error input
	syscall
	j continue2
continue4:
	li $v0,4 
	la $a0,shape
	syscall
	
	li $v0,5
	syscall
	move $s5, $v0
	
	bge $s5,1,continue5
	li $v0,4 
	la $a0,error2			#check if error input
	syscall
	j continue4
continue5:
	
	blt $s5,5,continue6
	li $v0,4 
	la $a0,error2			#check if error input
	syscall
	j continue4
continue6:
	
	bne $s5,1, next1		#branch to the correct shape and calculate
	j rectangleT
next1:
	bne $s5,2,next2
	j cubeT
next2:
	bne $s5,3,next3
	j cylinderT
next3:
	bne $s5,4,next4
	j pyramidT
next4:
	
rectangleT:
back1:
	li $v0,4
	la $a0,input1		#input edge a
	syscall
	
	li $v0, 7
	syscall
	mov.d  $f2, $f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f2       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move1
	
	li $v0,4
	la $a0,negative		#check if the input is negative
	syscall
	
	j back1
	

move1:	
	li $v0,4
	la $a0,input2		#input edge b
	syscall
	
	li $v0,7
	syscall
	mov.d $f4,$f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f4      # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move2
	
	li $v0,4
	la $a0,negative		#check if the input is negative
	syscall
	
	j move1
	
move2:	
	li $v0,4
	la $a0,input3		#input edge c
	syscall
	
	
	li $v0,7
	syscall
	mov.d $f6,$f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f6      # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move3
	
	li $v0,4
	la $a0,negative		#check if the input is negative
	syscall
	
	j move2
move3:	
	
	beq $s7,1,volume_rectangle		#branch to other mode
	beq $s7,2,total_rectangle
	
	mul.d $f8,$f2,$f4
	mul.d $f8,$f8,$f6
	
	li $v0,4
	la $a0,volume
	syscall
	
	li $v0,4
	la $a0,rectangle			#print out the volume and result
	syscall
	
	li $v0,3
	mov.d $f12,$f8		
	syscall
	
	jal metric_mode3			#print metric
	
	mul.d $f8, $f2,$f4
	mul.d $f10,$f2,$f6
	add.d $f8,$f8,$f10
	mul.d $f10,$f4,$f6
	add.d $f8,$f8,$f10
	
	l.d $f10,double_2
	
	mul.d $f8,$f8,$f10
	
	li $v0,4
	la $a0,area				#print out the total area and result
	syscall
	
	li $v0,4
	la $a0,rectangle
	syscall
	
	li $v0,3
	mov.d $f12,$f8
	syscall
	
	jal metric_mode2			#print out the metric
	j exit
volume_rectangle:
	mul.d $f8,$f2,$f4
	mul.d $f8,$f8,$f6
	
	li $v0,4
	la $a0,volume				#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,rectangle
	syscall
	
	li $v0,3
	mov.d $f12,$f8
	syscall
	
	jal metric_mode3	
	j exit	
total_rectangle:
	mul.d $f8, $f2,$f4
	mul.d $f10,$f2,$f6
	add.d $f8,$f8,$f10
	mul.d $f10,$f4,$f6
	add.d $f8,$f8,$f10
	
	l.d $f10,double_2
	
	mul.d $f8,$f8,$f10
	
	li $v0,4
	la $a0,area		#print out the total area and result
	syscall
	
	li $v0,4
	la $a0,rectangle
	syscall
	
	li $v0,3
	mov.d $f12,$f8
	syscall
	
	jal metric_mode2
	j exit
	
			
cubeT:
	li $v0,4
	la $a0,input_cube
	syscall
	
	li $v0, 7
	syscall
	mov.d  $f2, $f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f2       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move4
	
	li $v0,4
	la $a0,negative		#check if input is negative
	syscall
	
	j cubeT
move4:	
	beq $s7,1,volume_cube
	beq $s7,2,total_cube
	
	mul.d $f4,$f2,$f2
	mul.d $f4,$f4,$f2
	
	li $v0,4
	la $a0,volume				#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,cube
	syscall
	
	li $v0,3
	mov.d $f12,$f4
	syscall
	
	jal metric_mode3
	
	mul.d $f4,$f2,$f2
	l.d $f6,double_6
	
	mul.d $f4,$f4,$f6
	
	li $v0,4
	la $a0,area				#print out the area and result
	syscall
	
	li $v0,4
	la $a0,cube
	syscall
	
	li $v0,3
	mov.d $f12,$f4
	syscall
	
	jal metric_mode2
	j exit
volume_cube:
	mul.d $f4,$f2,$f2
	mul.d $f4,$f4,$f2
	
	li $v0,4
	la $a0,volume				#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,cube
	syscall
	
	li $v0,3
	mov.d $f12,$f4
	syscall
	
	jal metric_mode3
	j exit
total_cube:
	mul.d $f4,$f2,$f2
	l.d $f6,double_6
	
	mul.d $f4,$f4,$f6
	
	li $v0,4	
	la $a0,area				#print out the area and result
	syscall
	
	li $v0,4
	la $a0,cube
	syscall
	
	li $v0,3
	mov.d $f12,$f4
	syscall
	
	jal metric_mode2
	j exit
				
cylinderT:
	li $v0,4
	la $a0,input_height_cylinder
	syscall
	
	li $v0, 7
	syscall
	mov.d  $f2, $f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f2       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move5
	
	li $v0,4
	la $a0,negative			#check if negative
	syscall
	
	j cylinderT
move5:
		
	li $v0,4
	la $a0,input_radius_cylinder
	syscall
	
	li $v0,7
	syscall
	mov.d $f4,$f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f4       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move6
	
	li $v0,4
	la $a0,negative		#check if negative
	syscall
	
	j move5
move6:
		
	beq $s7,1,volume_cylinder
	beq $s7,2,total_cylinder
	
	l.d $f10,pi_double

	mul.d $f6,$f4,$f4
	mul.d $f6,$f6,$f10
	mul.d $f6,$f6,$f2
	
	li $v0,4
	la $a0,volume			#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,cylinder
	syscall
	
	li $v0,3
	mov.d $f12,$f6
	syscall
	
	jal metric_mode3
	
	l.d $f8,double_2
	
	mul.d $f6,$f4,$f8
	mul.d $f6,$f6,$f10
	mul.d $f6,$f6,$f2
	
	mul.d $f2,$f4,$f4
	mul.d $f2,$f2,$f10
	mul.d $f2,$f2,$f8
	
	add.d $f6,$f6,$f2

	
	
	li $v0,4
	la $a0,area				#print out the total area and result
	syscall
	
	li $v0,4
	la $a0,cylinder
	syscall
	
	li $v0,3
	mov.d $f12,$f6
	syscall
	
	jal metric_mode2
	j exit
volume_cylinder:
	l.d $f10,pi_double

	mul.d $f6,$f4,$f4
	mul.d $f6,$f6,$f10
	mul.d $f6,$f6,$f2
	
	li $v0,4
	la $a0,volume				#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,cylinder
	syscall
	
	li $v0,3
	mov.d $f12,$f6
	syscall
	
	jal metric_mode3
	j exit
total_cylinder:
	l.d $f10,pi_double

	l.d $f8,double_2
	
	mul.d $f6,$f4,$f8
	mul.d $f6,$f6,$f10
	mul.d $f6,$f6,$f2
	
	mul.d $f2,$f4,$f4
	mul.d $f2,$f2,$f10
	mul.d $f2,$f2,$f8
	
	add.d $f6,$f6,$f2
	
	li $v0,4
	la $a0,area			       #print out the total area and result
	syscall
	
	li $v0,4
	la $a0,cylinder
	syscall
	
	li $v0,3
	mov.d $f12,$f6
	syscall
	
	jal metric_mode2
	j exit
pyramidT:
	li $v0,4
	la $a0,input_height_pyramid
	syscall
	
	li $v0, 7
	syscall
	mov.d  $f2, $f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f2       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move7
	
	li $v0,4
	la $a0,negative			#check if negative input
	syscall
	
	j pyramidT

move7:	
	
	li $v0,4
	la $a0,input_edgea_pyramid
	syscall
	
	li $v0,7
	syscall
	mov.d $f4,$f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f4      # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move8
	
	li $v0,4
	la $a0,negative		#check if negative input
	syscall
	
	j move7
move8:	
	li $v0,4
	la $a0,input_edgeb_pyramid
	syscall
	
	li $v0,7
	syscall
	mov.d $f6,$f0
	
	li $t5,0
	mtc1 $t5,$f14
   	c.lt.d  $f14, $f6      # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t move9
	
	li $v0,4
	la $a0,negative		#check if negative input
	syscall
	
	j move8
move9:	
	beq $s7,1,volume_pyramid			#branch 
	beq $s7,2,total_pyramid
	
	mul.d $f8,$f4,$f6
	mul.d $f8,$f8,$f2
	
	l.d $f10,double_3
	div.d $f8,$f8,$f10
	
	li $v0,4
	la $a0,volume					#print out the volume and result
	syscall
	
	li $v0,4
	la $a0,pyramid
	syscall
	
	li $v0,3
	mov.d $f12,$f8
	syscall
	
	jal metric_mode3
	
	l.d $f10,double_2
	
	div.d $f16,$f4,$f10				
	mul.d $f16,$f16,$f16
	mul.d $f18,$f2,$f2
	
	add.d $f20,$f16,$f18
	
	sqrt.d $f20,$f20					#get the height of first triangle
	
	div.d $f16,$f6,$f10
	mul.d $f16,$f16,$f16
	mul.d $f18,$f2,$f2
	
	add.d $f22,$f16,$f18
	
	sqrt.d $f22,$f22					#get the height of second triangle
	
	mul.d $f20,$f20,$f6
	mul.d $f22,$f22,$f4						#calculate each area of 2 triagnle 
	
	add.d $f20,$f20,$f22						#sum
	mul.d $f22,$f4,$f6					
	add.d $f20,$f20,$f22
	
	li $v0,4
	la $a0,area
	syscall
	
	li $v0,4
	la $a0,pyramid						#print out the area and result
	syscall
	
	li $v0,3
	mov.d $f12,$f20
	syscall
	
	jal metric_mode2
	
	j exit
volume_pyramid:
		
	mul.d $f8,$f4,$f6				
	mul.d $f8,$f8,$f2
	
	l.d $f10,double_3
	div.d $f8,$f8,$f10
	
	li $v0,4
	la $a0,volume						#print out the volume
	syscall
	
	li $v0,4
	la $a0,pyramid
	syscall
	
	li $v0,3
	mov.d $f12,$f8
	syscall
	
	jal metric_mode3
	j exit
total_pyramid:
	l.d $f10,double_2
	
	div.d $f16,$f4,$f10
	mul.d $f16,$f16,$f16					#get the height of first triangle
	mul.d $f18,$f2,$f2	
	
	add.d $f20,$f16,$f18
	
	sqrt.d $f20,$f20
	
	div.d $f16,$f6,$f10
	mul.d $f16,$f16,$f16					#get the height of second triangle	
	mul.d $f18,$f2,$f2
	
	add.d $f22,$f16,$f18
	
	sqrt.d $f22,$f22
	
	mul.d $f20,$f20,$f6				
	mul.d $f22,$f22,$f4					#calculate each area of 2 triagnle 
	
	add.d $f20,$f20,$f22					#sum
	mul.d $f22,$f4,$f6
	add.d $f20,$f20,$f22
	
	li $v0,4
	la $a0,area						#Print out the total area and result
	syscall
	
	li $v0,4
	la $a0,pyramid
	syscall
	
	li $v0,3
	mov.d $f12,$f20
	syscall
	
	jal metric_mode2
	
	j exit

metric_mode2:
	beq $s6,1,cm_mode2
	beq $s6,2,dm_mode2
	beq $s6,3,m_mode2				
	
	li $v0,4
	la $a0,inche2
	syscall
	jr $ra
cm_mode2:
	li $v0,4
	la $a0,cm2			#print cm^2
	syscall
	jr $ra
dm_mode2:				#print dm^2
	li $v0,4
	la $a0,dm2
	syscall
	jr $ra
m_mode2:				#print m^2
	li $v0,4
	la $a0,m2
	syscall
	jr $ra

metric_mode3:
	beq $s6,1,cm_mode3
	beq $s6,2,dm_mode3
	beq $s6,3,m_mode3
	
	li $v0,4
	la $a0,inche3
	syscall
	jr $ra
cm_mode3:				#print cm^3
	li $v0,4
	la $a0,cm3
	syscall
	jr $ra
dm_mode3:				#print dm^3
	li $v0,4
	la $a0,dm3
	syscall
	jr $ra
m_mode3:				#print m^3
	li $v0,4
	la $a0,m3
	syscall
	jr $ra	
		
	
	
exit:	li $v0,10
    	syscall

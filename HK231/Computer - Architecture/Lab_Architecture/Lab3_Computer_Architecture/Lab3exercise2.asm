.data
	double_e: .double 1.0			#ID number 2252280 e = 0 so choose e = 1 as follow of the instructor
	inputa: .asciiz "Please input a: "
	inputb: .asciiz "Please input b: "
	inputc: .asciiz "Please input c: "
	inputd: .asciiz "Please input d: "
	inputu: .asciiz "Please input u: "
	inputv: .asciiz "Please input v: "
	output: .asciiz "The following integral f(x) = "
	error: .asciiz "Error cannot divide to 0"
	double_3: .double 3.0
	double_5: .double 5.0
	double_4: .double 4.0
	
.text
	li $v0,4					#this phase we call the input from the user
	la $a0,inputa					
	syscall
	
	li $v0,7
	syscall
	mov.d $f2,$f0
	
	li $v0,4
	la $a0,inputb
	syscall
	
	li $v0,7
	syscall
	mov.d $f4,$f0
	
	li $v0,4
	la $a0,inputc
	syscall
	
	li $v0,7
	syscall
	mov.d $f6,$f0
	
	li $v0,4
	la $a0,inputd
	syscall
	
	li $v0,7
	syscall
	mov.d $f8,$f0
	
	li $v0,4
	la $a0,inputu
	syscall
	
	li $v0,7
	syscall
	mov.d $f10,$f0
	
	li $v0,4
	la $a0,inputv
	syscall
	
	li $v0,7
	syscall
	mov.d $f14,$f0
first_doing:								# first integral x^5
	mul.d $f16,$f10,$f10
	mul.d $f16,$f16,$f10
	mul.d $f16,$f16,$f10
	mul.d $f16,$f16,$f10
	
	mul.d $f18,$f14,$f14
	mul.d $f18,$f18,$f14
	mul.d $f18,$f18,$f14
	mul.d $f18,$f18,$f14
	
	
	sub.d $f20,$f16,$f18

	l.d $f16,double_5
	
	div.d $f20,$f20,$f16
	mul.d $f20,$f20,$f2
	add.d $f22,$f22,$f20
second_doing:								# second integral x^4
	mul.d $f16,$f10,$f10
	mul.d $f16,$f16,$f10
	mul.d $f16,$f16,$f10

	
	mul.d $f18,$f14,$f14
	mul.d $f18,$f18,$f14
	mul.d $f18,$f18,$f14

	
	sub.d $f20,$f16,$f18

	l.d $f16,double_4
	
	div.d $f20,$f20,$f16	
	mul.d $f20,$f20,$f4
	add.d $f22,$f22,$f20
third_doing:								# third integral x^3
	mul.d $f16,$f10,$f10
	mul.d $f16,$f16,$f10

	
	mul.d $f18,$f14,$f14
	mul.d $f18,$f18,$f14

	
	sub.d $f20,$f16,$f18

	l.d $f16,double_3
	
	div.d $f20,$f20,$f16	
	mul.d $f20,$f20,$f6
	add.d $f22,$f22,$f20
fourth_doing:								# third integral x
	sub.d $f20,$f10,$f14
	mul.d $f20,$f20,$f8
	add.d $f22,$f22,$f20	
	
	l.d $f16,double_e
	
	li $t5,0
	mtc1 $t5,$f18
   	c.eq.d  $f18, $f16       # Compare $f2 with 0.0 and set the FP condition bit
   	bc1t zero
   	
   	mul.d $f16,$f16,$f16
   	div.d $f22,$f22,$f16
   	
   	li $v0,4			#printout the output and the result
   	la $a0,output
   	syscall
   	
   	li $v0,3
   	mov.d $f12,$f22
   	syscall
   	
   	li $v0,10
   	syscall
   
zero:					#incase the e is zero
	li $v0,4
	la $a0,error
	syscall
	
	li $v0,10
	syscall
   	

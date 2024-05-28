.data
    array:.space 80      #4*20 bytes
    cout:.asciiz "Enter the 20 Elements"

.text   
    la $a0,cout			#prunt
    li $v0,4
    syscall 
    	 	
    	 			
    jal input			
    addi $t0, $t0, 4
    jal output			
    li $v0,10
    syscall

input:     
    beq $t0,-80,exit   	
    li $v0,5			# input
    syscall
    sw $v0,array($t0)		#Store array
    sub $t0,$t0,4		
    j input			
    
output:
    beq $t0, 4, exit		
    lw $a0, array($t0)	    
    li $v0, 1			#Print arrray
    syscall
    li $v0, 11 			
    li $a0, ' '	 
    syscall
    add $t0,$t0,4		
    j output			

exit:
    jr $ra			#Move back to main

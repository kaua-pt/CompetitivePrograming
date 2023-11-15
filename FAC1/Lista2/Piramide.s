.data 
    quebraL: .asciiz "\n"
    esp: .asciiz " "
    z: .asciiz "0" 
.text

    print112:
        li $v0,1
        move $a0,$t3 #numero
        syscall 

        li $v0,4
        la $a0,esp #espaco
        syscall

        j voltinha2


    print102:
        li $v0,4
        la $a0,z #zero
        syscall 

        li $v0,1
        move $a0,$t3 #numero
        syscall 

        li $v0,4
        la $a0,esp #espaco
        syscall

        j voltinha2

    print11:
        # loop
        move $t5,$t3

        loop101:
        li $v0,1
        move $a0,$t3 #numero
        syscall 
        li $v0,4
        la $a0,esp #espaco
        syscall

        sub $t5,$t5,1
        beq $t5,0,voltinha
        j loop101


    print10:
        # loop
        move $t5,$t3

        loop10:
        # printar
            li $v0,4
            la $a0,z #zero
            syscall 
            li $v0,1
            move $a0,$t3 #numero
            syscall 
            li $v0,4
            la $a0,esp #espaco
            syscall

        sub $t5,$t5,1
        beq $t5,0,voltinha
        j loop10

    piramide1:
        li $t3, 1         #numero inicial para printar

        loop:
            slti $t4, $t3, 10 	# $t0 = ($t3 < $t1) ? 1 : 0
            beq	$t4, 1, print10 # printa com 0
            beq	$t4, 0, print11 # printa sem 0

        voltinha:
            li $v0,4
            la $a0,quebraL #\n
            syscall
            addi $t3, $t3 ,1

        slt	$t6, $t0, $t3		# $t0 = ($s0 < $t3) ? 1 : 0
        beq $t6, $zero,loop

        li $v0,4
        la $a0,quebraL #\n
        syscall

        j piramide2

    piramide2:
        li $t7,1 # contador de linhas
        move $t3, $zero

        loop21:
            addi $t3, $t3 ,1
            slti $t4, $t3, 10 	# $t0 = ($t3 < $t1) ? 1 : 0
            beq	$t4, 1, print102 # printa com 0
            beq	$t4, 0, print112 # printa sem 0

        voltinha2:
            bne	$t3, $t7, loop21
            
            li $v0,4
            la $a0,quebraL #\n
            syscall

            addi $t7, $t7 ,1
            slt	$t6, $t0, $t7		# $t0 = ($s0 < $t7) ? 1 : 0
            move $t3, $zero
            beq $t6, $zero,loop21

        j finalizar

    main:
        li $v0, 5
        syscall
        move $t0,$v0    # t0 eh N
        j piramide1

    finalizar:
    li $v0,10
    syscall
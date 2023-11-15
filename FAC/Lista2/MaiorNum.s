.data
.text 

    ehMaior:
        move $t1,$v0
        j volta

    #primeira chamada, puxar numero de rep
    main:
        li $v0, 5
        syscall
        move $t0,$v0
        li $t1,-2147483648
        li $t2,0 #t2 = contador do loop , se for igual a t0, ele encerra

    #loop e comparação
    compara:
        li $v0, 5
        syscall
        # comparar se v0 > t1 
        slt	$t3, $t1, $v0	# $t3 = ($t1 < $v0) ? 1 : 0
        beq	$t3, 1, ehMaior	# if  == $t3 then goto target
        volta:
        addi $t2, $t2, 1			# $t2 = $t2 + 1
        bne	$t0, $t2, compara	# if  != $t1 then goto target
    
    move $a0,$t1
    li $v0,1
    syscall

    #finalizar programa
    li $v0,10
    syscall
        
        
        
        
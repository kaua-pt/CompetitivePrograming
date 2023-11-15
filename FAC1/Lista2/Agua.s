.data
.text 
    ateDez:
        li $t1,7
        j volta
    ateTrinta:
        li $t1,7
        sub $t3, $t0, 10	# $t0 = $t0 - 7
        mul $t0, $t3, 1
        add $t1, $t1,$t0
        j volta
    ateCem:
        li $t1,27
        sub $t3, $t0, 30	# $t0 = $t0 - 27
        mul $t0, $t3, 2
        add $t1, $t1,$t0
        j volta
    paraDeUsarAgua:
        li $t1,167
        sub $t3, $t0, 100	# $t0 = $t0 - 167
        mul $t0, $t3, 5
        add $t1, $t1,$t0
        j volta

    #primeira chamada, puxar numero de rep
    main:
        li $v0, 5
        syscall
        move $t0,$v0 #t0 é o consumo
        slt $t2,$t0,11
        beq	$t2, 1, ateDez	
        slt $t2,$t0,31
        beq	$t2, 1, ateTrinta	
        slt $t2,$t0,101
        beq	$t2, 1, ateCem
        j paraDeUsarAgua	
        volta:
    
    move $a0,$t1
    li $v0,1
    syscall

    #finalizar programa
    li $v0,10
    syscall
        
        
        
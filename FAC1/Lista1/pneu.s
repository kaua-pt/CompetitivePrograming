.data
.text
    main:
    #ler primeiro numero e mover variavel
    li $v0,5
    syscall
    move $t0,$v0


    #ler segundo numero e mover variavel
    li $v0,5
    syscall
    move $t1,$v0

    #subtrair numeros e printar na tela
    sub $t0,$t0,$t1
    move $a0,$t0
    li $v0,1
    syscall

    #finalizar programa
    li $v0,10
    syscall
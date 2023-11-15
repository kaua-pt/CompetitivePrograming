.data

.text
    main:
    #ler
    li $v0, 5
    syscall

    #mover
    move $t0, $v0

    #ler
    li $v0, 5
    syscall

    #mover
    move $t1, $v0

    #adicionar
    add $t0,$t0,$t1

    #imprimir
    li $v0, 1
    move $a0, $t0
    syscall

    #finalizar
    li $v0, 10
    syscall
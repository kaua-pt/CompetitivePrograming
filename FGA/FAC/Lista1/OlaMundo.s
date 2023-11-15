.data
    string: .asciiz "Ola Mundo\n"
.text 
    main:
    # pegar variavel do rótulo
    la $a0, string

    #carregar codigo syscall e printar
    li $v0, 4
    syscall

    #finalizar programa
    li $v0, 10
    syscall
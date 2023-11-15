.data
    nome: .space 100
    cmp: .space 100
.text 

    acerto:
        addi $s1,$s1,1
        j proceder

    main:
        li $s1,0 #numero de acertos

        li $v0, 5
        syscall
        move $t0,$v0 # t0 é o len da string

        #gabarito
        la $s2,nome# joga no $s porque tem que salvar string na memoria
        li $v0,8

        la $a0,nome
        li $a1,99
        syscall

        #resp
        la $s3,cmp
        li $v0,8

        la $a0,cmp
        li $a1,99
        syscall


    li $t1,0  # contador loop
    for:

        lb $t3, 0($s2) #load os caracteres da memoria 
        lb $t4, 0($s3) 
        beq $t3,$t4,acerto

        proceder:
            addi $s2,$s2,1 # soma bits
            addi $s3,$s3,1
            addi $t1,$t1,1 # soma contador
        bne $t0,$t1,for

    print:
        li $v0,1
        move $a0,$s1
        syscall

    #finalizar programa
    li $v0,10
    syscall
        
        
        
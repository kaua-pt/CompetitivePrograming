bitparidade:
    move    $t0, $zero          # cnt loop = 0
    move    $t1, $zero          # qnt 1's = 0
    move    $t2, $a0            # valor shift = num orig
    move    $v1, $a0            # valor shift = num orig
    addi    $t3, $zero, 7       # qnt loop = 7
    addi    $t5, $zero, 2       # const = 2
for:
    beq     $t0, $t3, fimFor    # if cnt loop = qnt loop -> jump fimFor

    andi    $t4, $t2, 1         # verifica o bit menos significativo
    
    beq     $t4, $zero, naoSoma # if bit menos significativo = 0 -> jump naoSoma
    addi    $t1, $t1, 1         # qnt 1's++
    
naoSoma:
    srl		$t2, $t2, 1			# $t2 = $t2 >> 1 faz o shift do valor, reduzindo um bit por vez
    
    addi    $t0, $t0, 1         # cnt loop ++
    j for                       # reinicia loop
fimFor:
#    rem     $t6, $t1, $t5       # t6 = t2 % t5
    div     $t1, $t5
    mfhi    $t6
    beq     $t6, $zero, par     # if t6 = 0 -> jump par
    addi    $v0, $zero, 1       # v0 = 1
    ori     $v1, $v1, 128 # altera o bit mais significativo
    j       fimProg             # jump fim prog
par:
    move    $v0, $zero          # v0 = 0
    ori     $v1, $v1, 0
fimProg:

    jr $ra                          # retorna linha padrão do programa

.data
Cel:    .byte 'C'
far:        .byte 'F'
kelvin:     .byte 'K'
F2C:  .float 5.0, 9.0, 32.0
C2K:  .float 273.15
nl:         .asciiz "\n"

.text
main:

    li $v0, 12
    syscall
    move $t0, $v0

    li $v0, 12
    syscall

    li $v0, 12
    syscall
    move $t1, $v0

    li $v0, 12
    syscall

    li $v0, 6
    syscall

    lb $s0, Cel

    beq $t0, $s0, celso
    
    lb $s0, far

    beq $t0, $s0, faren

kelvins:
    lb $s0, Cel

    beq $t1, $s0, KtoC

KtoF: 

    lwc1    $f2, C2K

    sub.s   $f0, $f0, $f2

    j CtoF

KtoC: 

    lwc1    $f2, C2K

    sub.s   $f0, $f0, $f2

    j finalizar

faren:

    lb $s0, Cel

    beq $t1, $s0, FtoC

FtoK: 

    la      $t3, F2C
    lwc1    $f2, 0($t3)
    lwc1    $f3, 4($t3)
    lwc1    $f4, 8($t3)
    
    div.s   $f1, $f2, $f3
    sub.s   $f0, $f0, $f4
    mul.s   $f0, $f0, $f1

    lwc1    $f2, C2K

    add.s   $f0, $f0, $f2

    j finalizar
 
FtoC: 

    la      $t3, F2C
    lwc1    $f2, 0($t3)
    lwc1    $f3, 4($t3)
    lwc1    $f4, 8($t3)
    
    div.s   $f1, $f2, $f3
    sub.s   $f0, $f0, $f4
    mul.s   $f0, $f0, $f1

    j finalizar

celso:

    lb $s0, far

    beq $t1, $s0, CtoF

CtoK: 

    lwc1    $f2, C2K

    add.s   $f0, $f0, $f2

    j finalizar

CtoF: 

    la      $t3, F2C
    lwc1    $f2, 0($t3)         # $f2 = 5.0
    lwc1    $f3, 4($t3)         # $f3 = 9.0
    lwc1    $f4, 8($t3)         # $f4 = 32.0

    div.s   $f1, $f3, $f2
    mul.s   $f1, $f1, $f0
    add.s   $f0, $f1, $f4

    j finalizar

finalizar:

    li $v0, 2
    mov.s $f12, $f0
    syscall

    li          $v0, 4
    la          $a0, nl
    syscall

    li          $v0, 10
    syscall
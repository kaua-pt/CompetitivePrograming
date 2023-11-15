.data
quebra: .asciiz     "\n"
zerin:  .float 0.0
.text

main:

    li $v0, 5
    syscall
    move $s0, $v0

    move $t0, $zero
    lwc1 $f1, zerin
    lwc1 $f2, zerin

loop:

    beq $t0, $s0, calculo

    li          $v0, 6
    syscall
    mov.s $f3, $f0

    add.s $f1, $f1, $f0

    li          $v0, 6
    syscall

    mul.s $f4, $f3, $f0

    add.s $f2, $f2, $f4

    addi $t0, $t0, 1

    j loop

calculo:
    div.s $f5, $f2, $f1

    li          $v0, 2
    mov.s       $f12, $f5
    syscall

    li          $v0, 4
    la          $a0, quebra

    syscall

    li          $v0, 10
    syscall
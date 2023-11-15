.data
quebra:     .asciiz     "\n"
cem:        .double  100.0

.text
main:
    li          $v0, 7
    syscall
    mov.d $f2, $f0

    li $v0, 7
    syscall
    mov.d $f4, $f0

    li $v0, 7
    syscall
    mov.d $f6, $f0
    ldc1  $f10, cem

    div.d $f4, $f4, $f10
    mul.d $f8, $f2, $f4
    add.d $f0, $f2, $f8
    
    div.d $f6, $f6, $f10
    mul.d $f8, $f2, $f6
    add.d $f0, $f0, $f8
    
    li          $v0, 3
    mov.d       $f12, $f0
    syscall

    li          $v0, 4
    la          $a0, quebra
    syscall

    li          $v0, 10
    syscall
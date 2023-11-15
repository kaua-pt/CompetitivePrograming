add	$t0, $t1, $t2	# $t0 = $t1 + $t2
sub	$t0, $t1, $t2	# $t0 = $t1 - $t2

li	$t1,1 		    # $t1 = 1
la	$t1, var1       # t1 = &var1
move $t0, $t1	    # $t0 = $t1 

lw	$t1, 0($s1)	    # puxa em $t1 oque está na base $s1 *const
sw	$t1, 0($s1)		# guarda em $t1 oque está na base $s1 *const

sll	$t0, $t1, 0		# $t0 = $t1 << 0
srl	$t0, $t1, 0	    # $t0 = $t1 >> 0
and	$t0, $t1, $t2	# $t0 = $t1 & $t2
or	$t0, $t1, $t2	#  = $t1 | $t2
nor	$t0, $t1, $t2	# $t0 = ~($t1 | $t2)

beq	$t0, $t1, target# if $t0 == $t1 then goto target
bne	$t0, $t1, target# if  != $t1 then goto target

j	target			# jump to 
jal	target			# jump to  and save position to $ra

slt	$t0, $s0, $s1	#  = ($s0 < $s1) ? 1 : 0

lb	$t1, 0($s1)		# load string 









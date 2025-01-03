.word 0x100 6
.word 0x101 4

	sll $sp, $imm1, $imm2, $zero, 1, 11				# Set $sp = 2048
	lw $a0, $imm1, $zero, $zero, 256, 0				# Load n from 0x100 address to $a0
	lw $a1, $imm1, $zero, $zero, 257, 0				# Load k from 0x101 address to $a1
    blt $zero, $a0, $zero, $imm2, 0, End            # jump to End if n < 0
    blt $zero, $a1, $zero, $imm2, 0, End            # jump to End if k < 0
	jal $ra, $zero, $zero, $imm2, 0, Binom			# Calculate $v0 = Binom(n, k)
	sw $v0, $imm1, $zero, $zero, 258, 0				# Store the return value ($v0) in 0x102 address
	halt $zero, $zero, $zero, $zero, 0, 0			# Halt execution, exit simulator

Base:
	add $v0, $imm1, $zero, $zero, 1, 0				# Set return value ($v0) to 1
	beq $zero, $zero, $zero, $imm2, 0, Exit			# Jump to Exit

Binom:
	sub $sp, $sp, $imm1, $zero, 4, 0				# reserve stack space for 4 items
	sw $zero, $sp, $imm1, $s0, 0, 0					# save $s0 in the stack
	sw $zero, $sp, $imm1, $ra, 1, 0					# save $ra in the stack
	sw $zero, $sp, $imm1, $a0, 2, 0					# save $a0 in the stack
	sw $zero, $sp, $imm1, $a1, 3, 0					# save $a1 in the stack
	
	# Base Section
    
	beq $zero, $a1, $zero, $imm2, 0, Base			# Jump to Base if k = 0
	sub $t0, $a0, $a1, $zero, 0, 0					# $t0 = n - k
	beq $zero, $t0, $zero, $imm2, 0, Base			# Jump to Base if n = k

	# Recursive Section
	sub $a0, $a0, $imm1, $zero, 1, 0				# Set n = n -1
	jal $ra, $zero, $zero, $imm2, 0, Binom			# Calculate $v0 = Binom(n - 1, k)
	add $s0, $v0, $zero, $zero, 0, 0				# Set $s0 = $v0
	sub $a1, $a1, $imm1, $zero, 1, 0				# Set k = k - 1
	jal $ra, $zero, $zero, $imm2, 0, Binom			# Calculate $v0 = Binom(n - 1, k - 1)
	add $v0, $v0, $s0, $zero, 0, 0					# $v0 = Binom(n - 1, k - 1) + Binom(n - 1, k)
	beq $zero, $zero, $zero, $imm2, 0, Exit			# Jump to Exit
		
Exit:
    lw $a1, $sp, $imm1, $zero, 3, 0                 # Restore $a1 from stack
    lw $a0, $sp, $imm1, $zero, 2, 0                 # Restore $a0 from stack
    lw $ra, $sp, $imm1, $zero, 1, 0                 # Restore $ra from stack
    lw $s0, $sp, $imm1, $zero, 0, 0					# Restore $s0 from stack
	add $sp, $sp, $imm1, $zero, 4, 0				# pop 4 items from stack
    beq $zero, $zero, $zero, $ra, 0, 0				# Return to the caller
    
End:
    halt $zero, $zero, $zero, $zero, 0, 0            # Halt execution, exit simulator


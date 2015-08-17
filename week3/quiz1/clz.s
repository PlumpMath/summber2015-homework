.syntax unified
.arch armv7-a
.text
.align 2
.thumb
.thumb_func

.global clz_asm
.type clz_asm, function

clz_asm:
  @ PROLOG
  push {lr}

  @ if ( x == 0 )
  cmp r0 #0
  beq .L1

  @ n = 1
  mov r1 #1


.L1: @ return 32
  mov r0 #32

.return:
  pop {pc}    @ EPILOG

.size clz_asm, .-findGCDv1
.end

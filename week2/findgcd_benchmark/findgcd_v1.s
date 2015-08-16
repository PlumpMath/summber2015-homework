.syntax unified
.arch armv7-a
.text
.align 2
.thumb
.thumb_func

.global findGCDv1
.type findGCDv1, function

findGCDv1:
  @ PROLOG
  push {lr}

  @ R0 = a, R1 = b
  @ R0 == R1: goto .return
  cmp r0, r1
  beq .return_a

  @ R0 > R1 => a -= b
  subs r0, r0, r1
  bgt .findGCDv1

  @ R0 < R1 => b -= a
  subs r1, r1, r0
  bgt .findGCDv1

.return:
  pop {pc}    @ EPILOG

.size findGCDv1, .-findGCDv1
.end

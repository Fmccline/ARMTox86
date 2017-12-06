push {r0,r1}
pop {r0,r1}


mov r0,r2
mov r0,#32

adr r1,.label
ldr r0,[r1]

movle r0,#10
add r0,r0,#20
add r1,r0,#20
add r0,#20
mov r1,r0


.label:
	.word 1000000

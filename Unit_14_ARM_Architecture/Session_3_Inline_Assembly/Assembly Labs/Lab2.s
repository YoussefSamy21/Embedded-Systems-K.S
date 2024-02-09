RESET       ;CPU    Entry point
            mov     r0, #5
            bl      main

main        
            mov     r2, #0x100
            str     r0, [r2]
            ldr     r3, [r2]

            bl      termination
subtract    
            sub     r0, r0, #1
            cmp     r0, #0
            bne     subtract
            mov     pc, lr

termination 
RESET       ;CPU    Entry point
            mov     r0, #05
            mov     r9, #0xff
            bl      main

main        
            mov     r2, #0x100
            str     r0, [r2]
            ldr     r3, [r2]
            STRB    r0, [r2, #0x1]
            STRB    r0, [r2, #0x2]
            STRB    r0, [r2, #0x3]
            STRB    r9, [r2, #0x18]
            LDRB    r7, [r2, #0x18]

            bl      termination
subtract    
            sub     r0, r0, #1
            cmp     r0, #0
            bne     subtract
            mov     pc, lr

termination 
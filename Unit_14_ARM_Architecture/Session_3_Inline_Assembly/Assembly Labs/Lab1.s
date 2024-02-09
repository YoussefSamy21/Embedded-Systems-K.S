RESET       ;CPU    Entry point
            mov     r0, #5
            bl      main

main        
            bl      subtract
            bl      termination
subtract    
            sub     r0, r0, #1
            cmp     r0, #0
            bne     subtract
            mov     pc, lr

termination 
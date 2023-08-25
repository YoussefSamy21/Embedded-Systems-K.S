.global RESET   @ make the RESET section visible from other files

RESET:
        ldr sp,=stack_top
        bl main

STOP:
        b STOP
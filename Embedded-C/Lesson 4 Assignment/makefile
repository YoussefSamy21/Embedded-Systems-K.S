# @copyrights Youssef Samy
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g  #g & gdwarf for debugging information if desired , gdwarf also needed for debugging in proteus
INCS = -I .
LIBS = 			# if required to Link with another libraries
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name = TIVAC_LED_TOGGLE


all: $(project_name).bin
	@echo "=====> Building is Done <===== "

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(project_name).elf : $(OBJ) $(ASOBJ) # linking stage
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
# .axf extension to be able to debug in Keil 

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
		rm *.o *.elf *.bin

clean:
	   rm *.elf *.bin


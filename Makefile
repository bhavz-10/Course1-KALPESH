#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This MAKE file contains the instructions for building the entire project.
# It is made for two different platforms so it is necessary to include the
# platform when running it.
#
# Use: make [C1M2] [PLATFORM=HOST, PLATFORM=MSP432]
#
# Build Targets:
#      This supports two different platforms and can compile multiple 
#      source files. 
#
# Platform Overrides:
#      PLATFORM=MSP432, the target is cross compiler for MSP432 ;
#      PLATFORM=HOST, the target is native compiler
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = C1M2
SIZE = size
#Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU=cortex-m4
	
	SOURCES = ./src/main.c \
		  ./src/memory.c \
		  ./src/data.c \
		  ./src/course1.c \
		  ./src/stats.c 
		  ./src/interrupts_msp432p401r_gcc.c \
		  ./src/startup_msp432p401r_gcc.c \
	  	  ./src/system_msp432p401r.c

	PLATFORM=MSP432
	CPPFLAGS = -DMSP432 $(INCLUDES)
	ARCH = thumb
	SPECS = nosys.specs
	MARCH = armv7e-m
	ABI = hard
	FPU = fpv4-sp-d16
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -std=c99 -Werror -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(MARCH) -mfloat-abi=$(ABI) -mfpu=$(FPU) -Wall -g -O0
endif
ifeq ($(PLATFORM), HOST)
	PLATFORM=HOST
	CPPFLAGS = -DHOST $(INCLUDES)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -std=c99 -Werror -Wall -g -O0
endif

OBJS = $(SOURCES:.c=.o)
ASM = $(SOURCES:.c=.asm)
I = $(SOURCES:.c=.i)
DEPS = $(SOURCES:.c=.d)

# using -c flag to stop before linking
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -S to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -E to generate preprocessed file , so i only need CPPFLAGS
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#using -E -M to generate dependency files  
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# compile-all will generate all object files for all source files without linking
.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ 
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASM) $(I) $(TARGET).out $(TARGET).map

.PHONY : debug
debug:
	@echo $(INCLUDES)

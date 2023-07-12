#******************************************************************************
# Copyright (C) 2023 by @author
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Abdel Halim Mansour is not liable for any misuse of this material
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

F_OUT = final



PLATFORM = HOST \
		   MSP432



G_FLAG = -Wall \
			-g \
			-O0 \
			-std=c99
			# -Werror \


SHELL=/bin/bash

SRC_DIR := ./src
OBJ_DIR := ./obj
INC_DIR := ./include

#---------------------------------------------------

OBJ = $(SOURCES:.c=.o)
PP = $(SOURCES:.c=.i)	
AS = $(SOURCES:.c=.asm)	
DS = $(SOURCES:.c=.d)	


#---------------------------------------------------


SOURCES = 	$(SRC_DIR)/main.c \
			$(SRC_DIR)/memory.c \
			$(SRC_DIR)/stats.c \
			$(SRC_DIR)/data.c \
			$(SRC_DIR)/course1.c 


INCLUDES = -I include/common/

#---------------------------------------------------


# Platform Dependant Variables
ifeq ($(PLATFORM),MSP432)
	# MSP432 dependant build options
	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES+= 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES+= 	-I include/CMSIS/ \
				-I include/msp432/

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(F_OUT).map -T $(LINKER_FILE) -lm
	
	# Compiler Flags
	CFLAGS = 	$(G_FLAG) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)


else
	
	CC = gcc
	CFLAGS = $(G_FLAG)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
	LDFLAGS = -lm

endif

#---------------------------------------------------
#---------------------------------------------------

ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif


ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

#---------------------------------------------------
#---------------------------------------------------

.PHONY: compile-all build clean assemble-all
assemble-all: $(AS)
compile-all: $(OBJ)

#---------------------------------------------------
#---------------------------------------------------
#---------------------------------------------------


build: $(T_OUT).out

$(T_OUT).out: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	

#---------------------------------------------------
#---------------------------------------------------
#---------------------------------------------------

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

#---------------------------------------------------
#---------------------------------------------------
#---------------------------------------------------
# Build all and run file
run: $(F_OUT).out
	./$(F_OUT).out

#---------------------------------------------------
#---------------------------------------------------
#---------------------------------------------------

clean:
	rm -f ${SRC_DIR}/*{.o,.out,.map,.asm,.i} $(F_OUT).out




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

include sources.mk                 


ifeq ($(filter clean run,$(MAKECMDGOALS)),)
	ifeq ($(strip $(PLATFORM)),)
	  $(error PLATFORM is empty; usa PLATFORM=HOST o PLATFORM=MSP432)
	endif
endif

ifeq ($(PLATFORM),MSP432)
  CC        = arm-none-eabi-gcc
  CPPFLAGS  = -DMSP432 $(INCLUDES_COMMON) $(INCLUDES_MSP432)
  CFLAGS    = -Wall -Werror -g -O0 -std=c99 \
              -mcpu=cortex-m4 -mthumb -march=armv7e-m \
              -mfloat-abi=hard -mfpu=fpv4-sp-d16
  SOURCES   = $(SOURCES_COMMON) $(SOURCES_MSP432)
  LDFLAGS   = -T ../msp432p401r.lds \
              -mcpu=cortex-m4 -mthumb -march=armv7e-m \
              -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
              --specs=nosys.specs
  SIZE      = arm-none-eabi-size
else ifeq ($(PLATFORM),HOST)
  CC        = gcc
  CPPFLAGS  = -DHOST $(INCLUDES_COMMON)
  CFLAGS    = -Wall -g -O0 -std=c99 #-Werror
  SOURCES   = $(SOURCES_COMMON)
endif

ifeq ($(COURSE1),1)        
CFLAGS += -DCOURSE1
$(info *** COURSE1 defined ***)
endif

ifeq ($(VERBOSE),1) 
CFLAGS += -DVERBOSE
$(info *** VERBOSE defined ***) 
endif

LD     = $(CC)
OBJS   = $(SOURCES:.c=.o)


%.o : %.c $(MAKEFILE_LIST)
	$(info **$(CFLAGS)**)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E -c $< -o $@

%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S -c $< -o $@

.PHONY: build
build: clean $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o main.out

.PHONY: run
run: 
	./main.out

.PHONY: clean
clean:
	rm -rf *.out *.i *.asm *.o

.PHONY: compile-all
compile-all: $(OBJS)

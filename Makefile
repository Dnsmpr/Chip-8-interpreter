CURRENT_DIR = $(shell pwd)
CC = gcc
OPT = -O0
SRC = $(CURRENT_DIR)/src
BUILD = $(CURRENT_DIR)/build
BUS_DIRECTORY = $(SRC)/Bus
CPU_DIRECTORY = $(SRC)/Cpu
MEMORY_DIRECTORY = $(SRC)/Memory
RESOURCES_DIRECTORY = $(SRC)/Resources

TARGET = $(BUILD)/bin
DEPFLAGS = -MP -MD
INCDIR = $(CURRENT_DIR) $(SRC) $(BUS_DIRECTORY) $(CPU_DIRECTORY) $(MEMORY_DIRECTORY) $(RESOURCES_DIRECTORY)
CFILES = $(foreach D, $(INCDIR), $(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))
CFLAGS=-Wall -g -Wstrict-prototypes -Wcast-align -Wundef -std=c11 $(foreach D, $(INCDIR), -I$(D)) $(DEPFLAGS) $(OPT)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(DEPFILES) $(TARGET)

-include $(DEPFILES)
CC = gcc

#-O0 do not optimize the generated code
#-g3 compile with debug information
CFLAGS = -O0 -g3 -m32

SRC = undead_code.c

#Suffix replacement within macro
OBJS = $(SRC:.c=.o)

TARGET = undead_code

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS)

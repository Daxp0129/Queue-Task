CC = gcc
CFLAGS = -Wall -g
TARGET = Queue
OBJS = Queue.o utility.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Queue.o:Queue.c utility.h
	$(CC) $(CFLAGS) -c Queue.c

utility.o: utility.c utility.h
	$(CC) $(CFLAGS) -c utility.c

clean:
	rm -f $(OBJS) $(TARGET)

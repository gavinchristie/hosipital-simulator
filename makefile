#Flags for compiler
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

#Directories where compiler can find things
INCLUDE = -Iinclude
BINDIR = ./bin/
SRCDIR = ./src/
OBJDIR = ./obj/

OBJS = $(OBJDIR)LinkedListAPI.o $(OBJDIR)PriorityQueueAPI.o $(OBJDIR)patient.o $(OBJDIR)simulation.o

PROGNAME = program
TESTLIST = testList
TESTQUEUE = testQueue

all: program testQueue testList

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(BINDIR)$(PROGNAME)

testQueue: $(OBJDIR)LinkedListAPI.o $(OBJDIR)PriorityQueueAPI.o $(OBJDIR)testPriorityQueue.o
	$(CC) $(OBJDIR)LinkedListAPI.o $(OBJDIR)PriorityQueueAPI.o $(OBJDIR)testPriorityQueue.o -o $(BINDIR)$(TESTQUEUE)

testList: $(OBJDIR)LinkedListAPI.o $(OBJDIR)testLinkedList.o
	$(CC) $(OBJDIR)LinkedListAPI.o $(OBJDIR)testLinkedList.o -o $(BINDIR)$(TESTLIST)

$(OBJDIR)main.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

$(OBJDIR)testPriorityQueue.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)testPriorityQueue.c -o $(OBJDIR)testPriorityQueue.o

$(OBJDIR)testLinkedList.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)testLinkedList.c -o $(OBJDIR)testLinkedList.o

$(OBJDIR)LinkedListAPI.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)LinkedListAPI.c -o $(OBJDIR)LinkedListAPI.o

$(OBJDIR)PriorityQueueAPI.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)PriorityQueueAPI.c -o $(OBJDIR)PriorityQueueAPI.o

$(OBJDIR)simulation.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)simulation.c -o $(OBJDIR)simulation.o

$(OBJDIR)patient.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)patient.c -o $(OBJDIR)patient.o

clean:
	rm $(OBJDIR)*.o $(BINDIR)$(PROGNAME) $(BINDIR)$(TESTQUEUE) $(BINDIR)$(TESTLIST)

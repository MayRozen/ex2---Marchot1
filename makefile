CC = gcc
AR = ar
CFLAGS = -Wall -g

all: my_graph my_Knapsack

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

my_graph: my_graph.o libmy_mat.a
	$(CC) $(CFLAGS) $^ -o $@

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

my_Knapsack: my_Knapsack.o libmy_mat.a
	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(CFLAGS) -c my_Knapsack.c


.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_Knapsack








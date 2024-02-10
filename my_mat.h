#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define WEIGHT_BAG 20
#define SIZE 5

void putInValues(int graph[10][10]); //Create a new matrix with the values the user in.

void ifPathItoJ(int graph[10][10]); //Retuen 1=true or 0=false.

void shortestPath(int graph[10][10]); //Print the shortest path between i and j.

int knapSack(int weights[], int values[], int selected_bool[]); //Question 2.


#endif


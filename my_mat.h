#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define GRAPH_SIZE 10
#define WEIGHT_BAG 20
#define SIZE 5

void putInValues(int graph[][GRAPH_SIZE]); //Create a new matrix with the values the user in.

void floydWarshall(int graph[][GRAPH_SIZE]);

void ifPathItoJ(int graph[][GRAPH_SIZE]); //Retuen 1=true or 0=false.

void shortestPath(int graph[][GRAPH_SIZE]); //Print the shortest path between i and j.

int knapSack(int weights[], int values[], int selected_bool[]); //Question 2.


#endif

#include <stdio.h>
#include "my_mat.h"

int max(int x, int y);

void putInValues(int graph[][GRAPH_SIZE]){ //Create a new matrix with the values the user in.

    for(int i=0; i<GRAPH_SIZE; i++){
        for(int j=0; j<GRAPH_SIZE; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

void floydWarshall(int graph[][GRAPH_SIZE]){
    for(int k=0; k<GRAPH_SIZE; k++){
        for(int i=0; i<GRAPH_SIZE; i++){
          for(int j=0; j<GRAPH_SIZE; j++){
                if((graph[i][j]==0) && (i!=j) && (graph[i][k]!=0) && (graph[k][j]!=0)){ //The first time we found that there is any path.
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
                else if((graph[i][k]!=0) && (graph[k][j]!=0) && (graph[i][j]>graph[i][k]+graph[k][j]) ){ //There is a better path.
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
}


void ifPathItoJ(int graph[][GRAPH_SIZE]){
    int i = 0;
    int j = 0;

    scanf("%d %d", &i, &j);

    if(graph[i][j] != 0){ //There is a path.
        printf("True\n"); //true
    }
    else{
        printf("False\n"); //false
    }
}

void shortestPath(int graph[][GRAPH_SIZE]){
    int i = 0;
    int j = 0;

    scanf("%d %d", &i, &j); 
    if(graph[i][j] != 0){
        printf("%d\n", graph[i][j]);
    }
    else{
        printf("-1\n");
    }
}

int knapSack(int weights[], int values[], int selected_bool[]){ //Question 2.

    int table[SIZE+1][WEIGHT_BAG+1] = {0};
    int ans = 0;

    for(int i=0; i<=SIZE; i++){
        for(int j=0; j<=WEIGHT_BAG; j++){

            if(i==0 || j==0){
                table[i][j] = 0; //There isn't any item in our bag.
            }
            else if(weights[i-1] <= j){ //The item's weight now is lower.
                table[i][j] = max(values[i-1]+table[i-1][j-weights[i-1]], table[i-1][j]);
            }
            else{
                table[i][j] = table[i-1][j]; //The former valuse was higher.
            }
        }
    }

    int w = WEIGHT_BAG;

    for(int i=SIZE; i>0; i--){
        if(table[i][w] != table[i-1][w]){ //The sum of the values now is different.
            ans = ans + values[i-1];
            w = w - weights[i-1];
            selected_bool[i-1] = 1;
        }
    }

    return ans; //Maximum value.
} 

int max(int x, int y){

    if(x>y){
        return x;
    }

    return y;
}






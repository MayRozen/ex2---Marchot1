#include <stdio.h>
#include "my_mat.h"

int main(){

    char input;
    int graph[GRAPH_SIZE][GRAPH_SIZE];

    do{
        scanf(" %c", &input);
        switch (input)
        {
        case 'A':
            putInValues(graph);
            floydWarshall(graph);
            
            break;
        case 'B':
            ifPathItoJ(graph);

            break;
        case 'C':
            shortestPath(graph);

            break;
        default:
            break;
        } 
    }
    while(input != 'D' /*|| input != EOF*/);
    
return 0;
}



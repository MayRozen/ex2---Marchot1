#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"

int main(){
    char input = 'z';
    int graph[GRAPH_SIZE][GRAPH_SIZE];

    printf("Please enter A, B or C to start or D or EOF if tou want to get out:");
    
    while(input != 'D' || input != EOF){
        input = getchar();
        if(input == 'A'){
            putInValues(graph);
        }
        else if(input =='B'){
            ifPathItoJ(graph);
        }
        else if(input =='C'){
            shortestPath(graph);
        }
    }

}



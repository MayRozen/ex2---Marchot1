#include "my_mat.h"

int ifPathRec(int graph[GRAPH_SIZE][GRAPH_SIZE], int start, int end, int check);
int max(int x, int y);

void putInValues(int graph[GRAPH_SIZE][GRAPH_SIZE]){ //Create a new matrix with the values the user in.
    int value = 0;

    for(int i=0; i<GRAPH_SIZE; i++){
        for(int j=0; j<GRAPH_SIZE; j++){
            scanf("%d", &value);
            graph[i][j] = value;
        }
    }
} 


void ifPathItoJ(int graph[GRAPH_SIZE][GRAPH_SIZE]){ //Retuen 1=true or 0=false.
    int i = 0;
    int j = 0;
    int check = 0;

    scanf("%d %d", &i, &j);
    int ans = ifPathRec(graph, i, j, check);

    if(ans == 1){ //If this value is 0 so there is no path from i to j.
        printf("True");
    }
    else{
        printf("False");
    }
}

int ifPathRec(int graph[GRAPH_SIZE][GRAPH_SIZE], int start, int end, int check){

    if(start == end){
        if(check == -1){
            return 0; //The path isn't continuous.
        }
        else{
            return 1; //The path is continuous or there is a one adge from "start" to "end".
        }
    }

    for(int k=0; k<GRAPH_SIZE; k++){ //Check if there is another path.
        if(start!=k && k!=end){
            if(graph[start][k] != 0){
                return ifPathRec(graph, k, end, check);
            }
            else{ //If there is a "fracture" during the path from start to end.
                check = -1;
            }
        }
    }
}


void shortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE]){
    int i = 0;
    int j = 0;
    int check = 0;
    int ans = 0;

    scanf("%d %d", &i, &j); 
    putInValues(graph);

    if(ifPathRec(graph, i, j, check) == 0){ //There isn't a path from i to j.
        printf("-1");
    }
    else{ //Let's check the shortest path fron i to j.
        for(int k=0; k<GRAPH_SIZE; k++){
            for(int i=0; i<GRAPH_SIZE; i++){
              for(int j=0; j<GRAPH_SIZE; j++){
                    if(graph[i][j] > graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }
    }

    if(ans == 0){ //There is a path.
        if(graph[i][j]<graph[j][i]){
            printf("%d\n", graph[i][j]);
        }
        else{
            printf("%d\n", graph[j][i]);
        }
    }
}

int knapSack(int weights[], int values[], int selected_bool[]){ //Question 2.

    int maxValue = 0; //The maximum value of the items.
    int table[SIZE][WEIGHT_BAG];

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<WEIGHT_BAG; j++){

            if(i==0 || j==0){
                table[i][j] = 0; //There isn't any item in our bag.
            }
            else if(j <= weights[i-1]){ //The item's weight now is lower.
                table[i][j] = max(values[i-1]+table[i-1][j-1], table[i-1][j]);
            }
            else{
                table[i][j] = table[i-1][j]; //The former valuse was higher.
            }
        }
    }

    int value = table[SIZE][WEIGHT_BAG];
    int w = WEIGHT_BAG;

    for(int i=SIZE; i>0; i--){
        if(value != table[i-1][w]){ //The sum of the values now is different.
            selected_bool[i] = 1;
            value = value - values[i-1];
            w = w - weights[i-1];
        }
    }

    return table[SIZE][WEIGHT_BAG];
} 

int max(int x, int y){

    if(x>y){
        return x;
    }

    return y;
}






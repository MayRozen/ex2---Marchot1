#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"

void printItems(int selected_bool[], char items[]);

int main(){
    char items[SIZE+1] = ""; //6 because "\0".
    int weights[SIZE] = {0};
    int values[SIZE] = {0};
    int selected_bool[SIZE] = {0};

    int val = 0;
    int w = 0;

    for(int i=0; i<SIZE; i++){

        char item = getchar();
        items[i] = item;

        scanf("%d", &val);
        values[i] = val;

        scanf("%d", &w);
        weights[i] = w;
    }

    int maxValue = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");
    printItems(selected_bool, items);

    return 0;
}

void printItems(int selected_bool[], char items[]){ //Prints the chosen items.
    
    for(int i=0; i<SIZE; i++){
        if(selected_bool[i] == 1){
            printf(" %c", items[i]);
        }
    }
}





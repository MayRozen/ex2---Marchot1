#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"

int main(){
    char items[SIZE] = "";
    int weights[SIZE] = {0};
    int values[SIZE] = {0};
    int selected_bool[SIZE] = {0};

    for(int i=0; i<SIZE; i++){

        scanf(" %c", &items[i]);
        scanf(" %d", &values[i]);
        scanf(" %d", &weights[i]);
    }

    int maxValue = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");

    for(int i=0; i<SIZE; i++){
        if(selected_bool[i] == 1){
            printf(" %c", items[i]);
        }
    }

    return 0;
}





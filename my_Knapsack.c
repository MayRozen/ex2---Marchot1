#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"

char* printItems(int selected_bool[], char items[], char result[]);


int main(){
    char items[SIZE+1] = ""; //6 because "\0".
    int weights[SIZE] = {0};
    int values[SIZE] = {0};
    int selected_bool[SIZE] = {0};

    int val = 0;
    int w = 0;

    for(int i=0; i<SIZE; i++){
        printf("Enter item:");
        char item = getchar();
        items[i] = item;

        printf("Enter it's value:");
        scanf("%d", &val);
        values[i] = val;

        printf("Enter it's weight:");
        scanf("%d", &w);
        weights[i] = w;

    }

    int maxValue = knapSack(weights, values, selected_bool);
    char result[maxValue];

    printItems(selected_bool, items, result);
    printf("The max value is:%d\n", maxValue);

    return 0;
}

char* printItems(int selected_bool[], char items[], char result[]){ //Prints the chosen items and init them to "result".

    for(int i=0; i<SIZE; i++){
        if(selected_bool[i] == 1){
            printf(" %c", items[i]);
            result[i] = items[i];
        }
    }

    return result;
}





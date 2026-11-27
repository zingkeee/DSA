/*#include <stdio.h>
#include <stdlib.h>

int main(){

    int number = 0;
    printf("Enter the number of grades: ");
    scanf("%d", &number);


char* grades = malloc(number * sizeof(char));

    if (!grades) {
        printf("Memory allocation failed\n");
        return 1;
    }

for(int i = 0; i < number; i++){
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]);
}

for(int i = 0; i < number; i++){
    printf(" %c", grades[i]);
}



    free(grades);
    grades == NULL;
    return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>


int main(){

    int number = 0;
    printf("Enter number of prices: ");
    scanf("%d", &number);

    float* prices = malloc(number * sizeof(float));
    if(!prices){
        printf("failed");
        return 1;
    }

    for(int i = 0; i < number; i++){
        printf("Enter price #%d: ", i + 1);
        scanf("%f", &prices[i]);
    }

    int newNumber = 0;
    printf("Enter new number of prices: ");
    scanf("%d", &newNumber);

    if(newNumber < number){}

    float* temp = realloc(prices, newNumber * sizeof(float));
    if(!temp){
        printf("failed");
        free(temp);
        return 1;
    }

    prices = temp;

    if(newNumber > number){
        for(int i = number; i < newNumber; i++){
            printf("Enter price #%d: ", i + 1);
            scanf("%f", &prices[i]);
        }

        for(int i = 0; i < newNumber; i++){
            printf("$%.2f ", prices[i]);
        }

    } else {
        for(int i = 0; i < newNumber; i++){
            printf("Enter new price #%d: ", i + 1);
            scanf("%f", &prices[i]);
        }

        for(int i = 0; i < newNumber; i++){
            printf("%.2f ", prices[i]);
        }
    }
     

    free(prices);
    prices == NULL;


    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    char key[32];
    int value;
}Pair;

Pair dictionary[MAX];
int count = 0;

void put(const char* key, int value){
    for(int i = 0; i < count; i++){
        if(strcmp(dictionary[i].key, key) == 0){
            dictionary[i].value = value;
            return;
        }
    }

    if(count < MAX){
        strncpy(dictionary[count].key, key, 31);
        dictionary[count].key[31] = '\0';
        dictionary[count].value = value;
        count++;
    }
}

int get(const char* key, int* result){
    for(int i = 0; i < count; i++){
        if(strcmp(dictionary[i].key, key) == 0){
            *result = dictionary[i].value;
            return 1;
        }
    }
    return 0;
}

int del(const char* key){
    for(int i = 0; i < count; i++){
        if(strcmp(dictionary[i].key, key) == 0){
            dictionary[i] = dictionary[count - 1];
            count--;
            return 1;
        }
    }
    return 0;
}

int main(void){
    put("apple", 3);
    put("banana", 7);
    put("apple", 10);            /* updates apple from 3 to 10 */

    int v;
    if (get("apple", &v))
        printf("apple = %d\n", v);
    if (!get("cherry", &v))
        printf("cherry not found\n");

    del("banana");
    printf("size = %d\n", count);
    return 0;
}


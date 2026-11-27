#include <stdio.h>

#define MAX 10

typedef struct node{
    int elem;
    struct node* next;
}Node, *NodePtr;

typedef NodePtr Dictionary[MAX];
typedef int SET[MAX];

Dictionary D;
NodePtr D[MAX];

void initialize(Dictionary D){
    int x;
    for(x = 0; x < MAX; x++){
        D[x] = NULL;
    }
}

void insert(Dictionary D, int elem){
    insert(D, 20) -> hash(20) -> 0 -> insert node into D[0]
}

void delete(Dictionary D, int elem){
    delete(D, 20) -> hash(20) -> 0 ->delete the node from D[0]
}
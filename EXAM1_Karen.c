#include<stdio.h>
#define MAX 9

typedef char String[50];

typedef struct {
    int radius;
    String flavor;
}CakeLayer;

typedef struct {
    CakeLayer Cake[MAX];
    int top;
}CAKE;

void initStack(CAKE *C) {
    C->top = -1;
}

int isEmpty(CAKE C) {
    return C.top == -1;
}

int isFull(CAKE C) {
    return C.top == MAX - 1;
}

void push(CAKE *C, CakeLayer Layer) {
    if (!isFull(*C)) {
        C->Cake[++C->top] = Layer;
    }
}

void pop(CAKE *C) {
    if (!isEmpty(*C)) {
        C->top--;
    }
}

CakeLayer top(CAKE C) {
    CakeLayer empty = {0, ""};
    if (!isEmpty(C)) {
        return C.Cake[C.top];
    }
    return empty;
}

void display(CAKE C) {
    int i;
    printf("\nCake stack:\n\n");
    if (isEmpty(C)) {
        printf("  (empty)\n");
        return;
    }

    for (i = C.top; i >= 0; i--) {
        printf("  [%d] %s (radius %d)\n", i, C.Cake[i].flavor, C.Cake[i].radius);
    }
}

/* Function to implement */
void pushLayer(CAKE *C,CakeLayer Layer);
int countRadius(CAKE *C, int radius);

/*
 * @brief Counts how many layers of a given radius exist in the stack
 * @param C pointer to the cake stack
 * @param radius integer value representing the layer radius
 * @return number of layers in the stack that match the given radius
 */
int countRadius(CAKE *C, int radius) {
    //write your code here...
    int count = 0;
    CAKE temp;
    initStack(&temp);

    while(!isEmpty(*C)){
        CakeLayer layer = top(*C);
        pop(C);
        if(layer.radius == radius){
            count++;
        }
        push(&temp, layer);
    }

    while(!isEmpty(temp)){
        CakeLayer layer = top(temp);
        pop(&temp);
        push(C, layer);
    }   
    return count;
}

/*
 * @brief Pushes a new cake layer into the CAKE stack following the rules
 *        uses the countRadius function to get the count of layers of the
 *        same radius in order to be within the stack constraints
 * @param C pointer to the cake stack
 * @param Layer is a CakeLayer structure containing radius and flavor of the new cake layer
 * @return void
 */
void pushLayer(CAKE *C, CakeLayer Layer) {
    //write your code here...

    if(isFull(*C)){
        printf("");
        return;
    } else if(countRadius(C, Layer.radius) == 3){
        printf("");
        return;
    } else if(!isEmpty(*C)){
        if(Layer.radius > top(*C).radius){
            printf("");
            return;
        }
    }
    push(C, Layer);
    printf("");

}

int main(){

    CAKE cake,fullcake,tempcake;
    int choice,temp;
    initStack(&cake);
    initStack(&fullcake);
    initStack(&tempcake);

    CakeLayer B1 = {7, "Chocolate"};
    CakeLayer B2 = {7, "Vanilla"};
    CakeLayer B3 = {7, "Mango"};
    CakeLayer B4 = {7, "Ube"};
    CakeLayer B5 = {7, "Yema"};
    CakeLayer S1 = {5, "Chocolate"};
    CakeLayer S2 = {5, "Vanilla"};
    CakeLayer S3 = {5, "Mango"};
    CakeLayer S4 = {5, "Ube"};
    CakeLayer S5 = {5, "Yema"};
    CakeLayer T1 = {3, "Chocolate"};
    CakeLayer T2 = {3, "Vanilla"};
    CakeLayer T3 = {3, "Mango"};
    CakeLayer T4 = {3, "Ube"};
    CakeLayer T5 = {3, "Yema"};



    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1: //push 1 layer

            pushLayer(&cake, B2);

            display(cake);

            break;
        case 2: //push only base

            pushLayer(&cake, B2);
            pushLayer(&cake, B1);
            pushLayer(&cake, B2);

            display(cake);

            break;

        case 3: //push 2 tiers

            pushLayer(&cake, B2);
            pushLayer(&cake, B3);
            pushLayer(&cake, B2);
            pushLayer(&cake, S2);
            pushLayer(&cake, S3);
            pushLayer(&cake, S2);

            display(cake);

            break;

        case 4: //push 3 tiers

            pushLayer(&cake, B4);
            pushLayer(&cake, B1);
            pushLayer(&cake, B4);
            pushLayer(&cake, S4);
            pushLayer(&cake, S1);
            pushLayer(&cake, S4);
            pushLayer(&cake, T4);
            pushLayer(&cake, T1);
            pushLayer(&cake, T4);

            display(cake);
            break;

        case 5: //push smaller tiers
            pushLayer(&cake, S3);
            pushLayer(&cake, S2);
            pushLayer(&cake, S3);
            pushLayer(&cake, T4);
            pushLayer(&cake, T2);
            pushLayer(&cake, T4);

            display(cake);

            break;
        case 6: //push when full, should error

            fullcake.top=MAX-1;
            pushLayer(&fullcake, T2);

            break;

        case 7: // check countRadius
            push(&tempcake, S2);
            push(&tempcake, S2);
            push(&tempcake, S2);

            temp=countRadius(&tempcake, S3.radius);

            printf("\n%d Layers have a radius of %d",temp,S3.radius);

            break;

        case 8: // push when 3 tiers are of same radius
            push(&tempcake, B5);
            push(&tempcake, B5);
            push(&tempcake, B5);
            pushLayer(&tempcake, B5);

            display(tempcake);

            break;


        case 9: //push if larger than life
            push(&tempcake, S2);
            pushLayer(&tempcake, B2);

            display(tempcake);

            break;

        default:
            printf("\nNot a valid choice");
            break;

    }

    return 0;

}
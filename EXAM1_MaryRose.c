#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX 6
#define MIN 10
typedef char String[50];

typedef struct{
    String name;  //name of gym class
    int duration; //in hours
    String instructor;
    int minSize;
} gymClass;

typedef struct node{
    gymClass C;
    struct node* link;  //head->C.instructor
} nodeType, *nodePtr;

typedef struct{
    nodePtr N;
    String Day;
    int count;
} gymDay;

typedef struct{
    gymDay dayOf[5];
    int count;
} gymSchedule;

int getDay(String Day);
void initialize(gymSchedule*);
void display(gymSchedule);
void loadDummyNodes(gymSchedule*);
nodePtr createNode(const char* name, int duration, const char* instructor, int minSize);

/* Function to implement */
void insertClass(gymSchedule*, gymClass, String);


/* ============================================================
 * ASSUMED helper implementations (not provided in the prompt).
 * These are my best guess based on how main() uses them, just
 * so the file compiles and we can test insertClass. Replace
 * these with your real versions if you already have them.
 * ============================================================
 */

int getDay(String Day) {
    // Monday=0 ... Friday=4, weekends return -1
    const char* weekdays[5] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(Day, weekdays[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void initialize(gymSchedule *G) {
    const char* weekdays[5] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    G->count = 0;
    for (int i = 0; i < 5; i++) {
        strcpy(G->dayOf[i].Day, weekdays[i]);
        G->dayOf[i].N = NULL;
        G->dayOf[i].count = 0;
    }
}

nodePtr createNode(const char* name, int duration, const char* instructor, int minSize) {
    nodePtr n = (nodePtr)malloc(sizeof(nodeType));
    strcpy(n->C.name, name);
    n->C.duration = duration;
    strcpy(n->C.instructor, instructor);
    n->C.minSize = minSize;
    n->link = NULL;
    return n;
}

void loadDummyNodes(gymSchedule *G) {
    // Preload a "Core" class on Tuesday, so case 6 (duplicate) has something to collide with.
    int idx = getDay("Tuesday");
    nodePtr n = createNode("Core", 1, "Reyes", 12);
    G->dayOf[idx].N = n;
    G->dayOf[idx].count++;
    G->count++;
}

void display(gymSchedule G) {
    printf("\nGym Schedule:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %s (%d classes):\n", G.dayOf[i].Day, G.dayOf[i].count);
        nodePtr cur = G.dayOf[i].N;
        while (cur != NULL) {
            printf("    - %s | %dhr | Instructor: %s | Min size: %d\n",
                   cur->C.name, cur->C.duration, cur->C.instructor, cur->C.minSize);
            cur = cur->link;
        }
    }
}

/* ============================================================
 * End of assumed helpers
 * ============================================================
 */


/*
 * @brief Inserts a new gym class into the schedule for a given day
 * @param G pointer to the gym schedule
 * @param newGC the new gymClass to be inserted
 * @param Day string representing the day of the week
 *
 */

void insertClass(gymSchedule* G, gymClass newGC, String Day) {
    //Write your code here...
    int day = getDay(Day);

    if(day == -1){
        return;
    } else if(G->dayOf[day].count >= MAX){
        return;
    } else if(strcmp(newGC.instructor, "0") == 0){
        return;
    } else if(newGC.minSize < MIN){
        return;
    } else if(newGC.duration > 1){
        return;
    } else if(){
        nodePtr current = G->dayOf[day].N;
        while(current != NULL){
            if(strcmp(newGC.name, current->C.name) == 0){
                return;
            } else {
                current = current->link;
            }
        }
        nodePtr newNode = createNode(newGC.name, newGC.duration, newGC.instructor, newGC.minSize);
        if(G->dayOf[day].N == NULL){
            G->dayOf[day].N = newNode;
        } else {
            nodePtr temp = G->dayOf[day].N;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = newNode;
        }
        G->count++;
        G->dayOf[day].count++;
        
        
    }

    





}


int main(){
    int choice;

    gymSchedule G; initialize(&G); loadDummyNodes(&G);
    gymSchedule J;
    initialize(&J);
    J.dayOf[0].count=6;
    String Day = "Monday";
    String otherDay = "Tuesday";
    String wrongDay = "Saturday";

    gymClass newGC = {"Core",1,"Menchavez",11};
    gymClass wrong1 = {"Core",1,"0",13};
    gymClass wrong2 = {"Core",2,"Menchavez",11};
    gymClass wrong3 = {"Core",1,"Menchavez",9};

    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1: //WrongDay
            printf("\nInserting new class Core on Saturday:\n");

            insertClass(&G, newGC, wrongDay);


               break;

        case 2: //MaxCount for the day

            printf("\nInserting new class in gymsched J (full) :\n");

            insertClass(&J, newGC, Day);


               break;

        case 3: //no Instructor

            printf("\nInserting new class without an instructor :\n");

            insertClass(&G, wrong1, Day);


               break;

        case 4: //duration more than 1 hour

            printf("\nInserting new class that is more than an hour :\n");

            insertClass(&G, wrong2, Day);


               break;

        case 5: //size of minsize

            printf("\nInserting new class that doesn't reach minimum size:\n");

            insertClass(&G, wrong3, Day);


               break;

        case 6: //duplicateClass on the day

            printf("\nInserting new class Core that is already in Tuesday:\n");

            insertClass(&G, newGC, otherDay);


               break;



        case 7: //insert


            insertClass(&G, newGC, Day);

            display(G);

               break;

        default:
            printf("\nNot a valid choice");
            break;

    }

    return 0;

}
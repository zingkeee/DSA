#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numVertices;
    int numEdges;
    int i;
    Graph *g;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    g = createGraph(numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Adjacency list:\n");
    printGraph(g);

    freeGraph(g);
    return 0;
}

void printGraph(const Graph *g) {
    int i;
    for (i = 0; i < g->numVertices; i++) {
        Node *cur = g->adjLists[i];
        printf("%d:", i);
        while (cur != NULL) {
            printf(" %d", cur->dest);
            cur = cur->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph *g) {
    int i;
    for (i = 0; i < g->numVertices; i++) {
        Node *cur = g->adjLists[i];
        while (cur != NULL) {
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(g->adjLists);
    free(g);
}

/* A node in an adjacency list. */
typedef struct Node {
    int dest;
    struct Node *next;
} Node;

/* Graph represented as an array of adjacency lists. */
typedef struct Graph {
    int numVertices;
    Node **adjLists;
} Graph;

/* Function prototypes */
Graph *createGraph(int numVertices);
void addEdge(Graph *g, int src, int dest);
void printGraph(const Graph *g);
void freeGraph(Graph *g);

#endif

/*
 * The graph is stored as an array of linked lists, one list per vertex.
 * adjLists[i] is the head of the list of vertices reachable from i.
 *
 *   vertex 0 -> [dest 2] -> [dest 1] -> NULL
 *   vertex 1 -> NULL
 *   vertex 2 -> NULL
 *
 * Edges are inserted at the FRONT of the list, so the most recently
 * added destination ends up first. printGraph (in main.c) walks each
 * list and prints the destination values in that order.
 */

Graph *createGraph(int numVertices) {
    /*
     * Build an empty graph with numVertices vertices and no edges.
     *
     * Step 1: malloc a Graph (sizeof(Graph)) and store the pointer.
     * Step 2: set g->numVertices = numVertices.
     * Step 3: malloc an array of numVertices node pointers for
     *         g->adjLists — use sizeof(Node *), NOT sizeof(Node).
     * Step 4: loop over every index i and set g->adjLists[i] = NULL,
     *         meaning "this vertex currently has no outgoing edges".
     * Step 5: return g.
     */

    /* TODO: implement the steps above. */

    Graph* g = malloc(sizeof(Graph));
    g->numVertices = numVertices;
    g->adjLists = malloc(numVertices * sizeof(Node*));
    for(int i = 0; i < numVertices; i++){
        g->adjLists[i] = NULL;
    }

    return g;
}

void addEdge(Graph *g, int src, int dest) {
    /*
     * Store the directed edge src -> dest by adding one node to the
     * list of vertex src.
     *
     * Step 1: validate the endpoints. If src or dest is < 0 or
     *         >= g->numVertices, the edge is invalid: return without
     *         storing anything.
     * Step 2: malloc one Node (sizeof(Node)).
     * Step 3: set newNode->dest = dest.
     * Step 4: link it in front of the current list:
     *         newNode->next = g->adjLists[src];
     *         g->adjLists[src] = newNode;
     *
     * Think about: why insert at the front instead of the back?
     * (Front insertion is O(1) and needs no traversal.)
     */

    /* TODO: implement the steps above. */

    if(src < 0 || dest < 0 || src >= g->numVertices || dest >= g->numVertices) return;

    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;


}
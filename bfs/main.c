#include <stdio.h>
#include <stdlib.h>

//node structure
struct node {
    int vertex;
    struct node *next;
};
//graph structure
struct graph {
    struct node **adjlists;
    int *visited;
    int numvertics;
};
//Queue structure
struct queue {
    int *array;
    int front, rear, size;
    unsigned int capacity;
};

struct node *createnode(int vertex) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->vertex = vertex;
    return newnode;
}

struct graph *creategraph(int numvertices) {
    struct graph *ggraph = (struct graph *) malloc(sizeof(struct graph));
    ggraph->numvertics = numvertices;
    ggraph->adjlists = ((struct node **) malloc(numvertices * sizeof(struct node *)));
    ggraph->visited = (int *) malloc(numvertices * sizeof(int));
    for (int i = 0; i < numvertices; ++i) {
        ggraph->adjlists[i] = NULL;
        ggraph->visited[i] = 0;
    }
    return ggraph;
}

// Function to add an edge to the graph
void addedge(struct graph *ggraph, int src, int dest) {
    struct node *newnode = createnode(dest);
    newnode->next = ggraph->adjlists[src];
    ggraph->adjlists[src] = newnode;
    newnode = createnode(src);
    newnode->next = ggraph->adjlists[dest];
    ggraph->adjlists[dest] = newnode;
}

struct queue *createqueue(unsigned int capacity) {
    struct queue *qqueue = (struct queue *) malloc(sizeof(struct queue));
    qqueue->capacity = capacity;
    qqueue->front = 0;
    qqueue->size = 0;
    qqueue->rear = capacity - 1;
    qqueue->array = (int *) malloc(qqueue->capacity * sizeof(int));
    return qqueue;
}

int isfull(struct queue *qqueue) {
    return (qqueue->size == 0);
}

int isempty(struct queue *qqueue) {
    return (qqueue->size == qqueue->capacity);
}

void enqueue(struct queue *qqueue, int item) {
    if (isfull(qqueue))
        return;
    qqueue->rear = (qqueue->rear + 1) % qqueue->capacity;
    qqueue->array[qqueue->rear] = item;
    qqueue->size = qqueue->size + 1;
}

int dequeue(struct queue *qqueue) {
    if (isempty(qqueue))
        return -1;
    int item = qqueue->array[qqueue->front];
    qqueue->front = (qqueue->front + 1) % qqueue->capacity;
    qqueue->size = qqueue->size - 1;
    return item;
}

void bfs(struct graph *ggraph, int startvertex) {
    struct queue *qqueue = createqueue(ggraph->numvertics);
    ggraph->visited[startvertex] = 1;
    enqueue(qqueue, startvertex);
    while (!isempty(qqueue)) {
        int currentvertex = dequeue(qqueue);
        printf("%d ", currentvertex);
        struct node *temp = ggraph->adjlists[currentvertex];
        while (temp) {
            int adjvertex = temp->vertex;
            if (!ggraph->visited[adjvertex]) {
                ggraph->visited[adjvertex] = 1;
                enqueue(qqueue, adjvertex);
            }
            temp = temp->next;
        }
    }
}


int main() {
    int numVertices = 6; // Number of vertices in the graph
    struct graph *graph = creategraph(numVertices); // Create the graph

    // Add edges to the graph
    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 4);
    addedge(graph, 3, 4);
    addedge(graph, 3, 5);
    addedge(graph, 4, 5);

    // Print the graph
    printf("Graph:\n");

    // Perform BFS traversal starting from vertex 0
    printf("BFS traversal starting from vertex 0: ");
    bfs(graph, 0);
    printf("\n");
    return 0;
}

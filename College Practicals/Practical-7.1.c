#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Graph structure
typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

// Function prototypes
void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int src, int dest);
void bfs(Graph* g, int start);
void dfs(Graph* g, int start, int visited[]);

void printCurrentTime(const char* name, const char* enrollment) {
    time_t t;
    time(&t);
    struct tm* local = localtime(&t);
    
    printf("Name: %s\n", name);
    printf("Enrollment Number: %s\n", enrollment);
    printf("Current Date and Time: %s", asctime(local));
}

int main() {
    char name[] = "Dave Pujan M.";   
    char enrollment[] = "230130107024";  
    printCurrentTime(name, enrollment);

    Graph g;
    initGraph(&g, 5);

    // Adding edges 
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    printf("BFS starting from vertex 0:\n");
    bfs(&g, 0);

    printf("DFS starting from vertex 0:\n");
    int visited[MAX] = {0};  
    dfs(&g, 0, visited);

    return 0;
}

//  initialize the graph
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adj[i][j] = 0;  
}

//  add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;  
    g->adj[dest][src] = 1;  
}

// BFS function
void bfs(Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS function
void dfs(Graph* g, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[start][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

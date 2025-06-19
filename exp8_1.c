#include <stdio.h>

#define MAX 100

void createAdjacencyMatrix(int matrix[MAX][MAX], int vertices, int edges) {
    int u, v;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (from to): ");
        scanf("%d%d", &u, &v);
        matrix[u][v] = 1;
    }
}

void printAdjacencyMatrix(int matrix[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int inDegree(int matrix[MAX][MAX], int vertices, int vertex) {
    int count = 0;
    for (int i = 0; i < vertices; i++) {
        if (matrix[i][vertex] == 1)
            count++;
    }
    return count;
}

int outDegree(int matrix[MAX][MAX], int vertices, int vertex) {
    int count = 0;
    for (int i = 0; i < vertices; i++) {
        if (matrix[vertex][i] == 1)
            count++;
    }
    return count;
}

int main() {
    int matrix[MAX][MAX] = {0};
    int vertices, edges, vertex;
    char choice;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    createAdjacencyMatrix(matrix, vertices, edges);
    printAdjacencyMatrix(matrix, vertices);

    printf("\nFind degrees? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Enter vertex index: ");
        scanf("%d", &vertex);
        printf("In-degree of vertex %d: %d\n", vertex, inDegree(matrix, vertices, vertex));
        printf("Out-degree of vertex %d: %d\n", vertex, outDegree(matrix, vertices, vertex));

        printf("\nFind degrees? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}

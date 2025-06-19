#include <stdio.h>

int main() {
    int n, i, j, isUndirected = 1;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adjMatrix[i][j] != adjMatrix[j][i]) {
                isUndirected = 0;
                break;
            }
        }
        if(!isUndirected)
            break;
    }

    if(isUndirected)
        printf("The graph is undirected.\n");
    else
        printf("The graph is directed.\n");

    return 0;
}

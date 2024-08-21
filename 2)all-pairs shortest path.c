#include <stdio.h>

#define INF 999 // Define a large value as infinity
#define MAX 10

void floydWarshall(int dist[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nThe distance matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, dist[MAX][MAX];

    printf("FLOYD-WARSHALL ALGORITHM\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    floydWarshall(dist, n);

    return 0;
}

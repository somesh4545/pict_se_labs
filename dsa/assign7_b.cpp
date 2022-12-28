#include <iostream>
using namespace std;

#define V 5

int find(int p[], int x)
{
    if (p[x] == x)
        return x;
    return find(p, p[x]);
}

void makeUnion(int p[], int x, int y)
{
    int a = find(p, x);
    int b = find(p, y);
    if (a == b)
        return;
    p[b] = a;
}

void kruskals(int graph[V][V])
{
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int no_edges = 0;
    while (no_edges < V - 1)
    {
        int min = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if ((find(parent, i) != find(parent, j)) && graph[i][j] != 0 && graph[i][j] < min)
                {
                    min = graph[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        no_edges++;
        makeUnion(parent, x, y);
        cout << x << "-" << y << " cost: " << min << endl;
    }
}

int main()
{

    int graph[V][V] = {
        {0, 0, 3, 0, 0},
        {0, 0, 10, 4, 0},
        {3, 10, 0, 2, 6},
        {0, 4, 2, 0, 1},
        {0, 0, 6, 1, 0},
    };

    kruskals(graph);

    return 0;
}

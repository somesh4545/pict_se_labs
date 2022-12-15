// Prim's algorithm

#include <iostream>
#include <limits.h>
using namespace std;

#define V 5

void findPrims(int g[V][V]){
    int visited[V];
    for(int i=0; i<V; i++){
        visited[i] = 0;
    }
    visited[0] = 1;

    int no_edge = 0;

    while(no_edge != V-1){
        int min = INT_MAX;
        int x = 0;
        int y = 0;

        for(int i=0; i<V; i++){
            if(visited[i]){
                for(int j=0; j<V; j++){
                    if(visited[j]==0 && g[i][j] > 0){
                        if(min > g[i][j]){
                            min = g[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << "Edge no: " << no_edge << " between " <<  x << "-" << y << " " << " cost= " << min << endl;
        visited[y] = 1;
        no_edge++;
    }
}

int main(){

//     int graph[V][V] = {
//       { INT_MAX, 12, INT_MAX, 25, INT_MAX },
//       { 12, INT_MAX, 11, 8, 12 },
//       { INT_MAX, 11, INT_MAX, INT_MAX, 17 },
//       { 25, 8, INT_MAX, INT_MAX, 15 },
//       { INT_MAX, 12, 17, 15, INT_MAX },
//    };

    int graph[V][V];

    cout << "Enter graph's nodes value 5-5: " << endl;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cin >> graph[i][j];
        }
    }

    findPrims(graph);

    return 0;
}
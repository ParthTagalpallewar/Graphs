#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9+10;

int graph[N][N];

int main(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        graph[x][y] = w;
    }

    //floyed warshall
    for(int k=1; k<=n; k++){

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                if(graph[i][k] == INF && graph[k][j] == INF) continue;

                graph[i][j] = min(graph[i][j], (graph[i][k]+graph[k][j]));

            }
        }
    }


    //printing value
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            
            if(graph[i][j] != INF)
                cout << graph[i][j] << " ";
            else
                cout << "I" << " ";
        }

        cout << endl;
    }

    return 0;
}
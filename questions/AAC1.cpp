#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nv;
    vector<int> *graph;

public:
    Graph(int n)
    {
        nv = n;
        graph = new vector<int>[n];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int shortest_path(int dst)
    {
        vector<int> visited(nv + 1, 0);
        queue<pair<int, int>> pq;
       
        visited[1] = 1;
        pq.push({1, 0});

        while (!pq.empty())
        {
            
            int v = pq.front().first;
            int d = pq.front().second;
            
            
            pq.pop();

            for (int child : graph[v])
            {
                if (visited[child] == 0)
                {   
                    
                    if (child == dst)
                        return d+1;

                    pq.push({child, d + 1});
                    visited[child] = 1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        Graph gh(m+10);

        for (int i = 0; i < m; i++)
        {

            int u, v;
            cin >> u >> v;

            gh.addEdge(u, v);
        }

        int ans = gh.shortest_path(n);

        cout << ans << endl;
    }

    return 0;
}
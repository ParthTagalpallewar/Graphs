#include<bits/stdc++.h>
using namespace std;


class Graph
{
    int nv;
    vector<pair<int, int>> *graph;

public:

    Graph();

    Graph(int n)
    {
        nv = n;
        graph = new vector<pair<int, int>>[n];
    }

    void addEdge(int u, int v, int w)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int dfs(pair<int, int> vertex, int parent=0)
    {

        if(graph[vertex.first].size() == 1 && parent!=0) return vertex.second;

        int _max = -1;

        for(pair<int, int> child: graph[vertex.first]){

            if(parent == child.first) continue;

            _max = max(dfs(child, vertex.first), _max);
        }
        if(_max != -1){
            return _max + vertex.second;
        } else{
            return vertex.second;
        }
    }
};

int main(){

    int t;
    cin >> t;

    Graph* gh;

    while(t-- > 0){

        int n;
        cin >> n;

        gh = new Graph(n+1);

        for(int i=0; i<n-1; i++){
            
            int u, v, d;
            cin >> u >> v >> d;

            gh->addEdge(u, v, d);

        }
        for(int i=1; i<=n; i++){
            
            cout << gh->dfs({i, 0}) << " ";

        }

        cout << endl;

      
    }

    return 0;
}


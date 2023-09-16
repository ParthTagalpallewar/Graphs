#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+7;

vector<pair<int, int>> graph[N];

void dijkastra(int source, int n){

    vector<bool> visited(N, false);
    vector<int> dist(N, INF);

    set<pair<int, int>> st;

    st.insert({0, source});
    dist[source] = 0;
    

    while(st.size() > 0){

        
        auto node = *st.begin();

        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if(visited[v]) continue;

       

        visited[v] = true;

        for(auto adj: graph[v]){

            int adj_v = adj.first;
            int dist_adj = adj.second;
         
            if (dist[v] + dist_adj < dist[adj_v])
            {              
                dist[adj_v] = dist[v] + dist_adj;
                st.insert({dist[adj_v], adj_v});
            }
        }


    }

    for(int i=1; i< n; i++){
        cout << dist[i] << endl;
    }

  

}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x, y, w;
        cin >> x >> y >> w;

        graph[x].push_back({y, w});

    }

    dijkastra(1, 7);


    return 0;
}
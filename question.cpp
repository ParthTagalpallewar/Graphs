#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 7;

vector<pair<int, int>> graph[N];

void dijkastra(int source, int n, int destination)
{

    vector<bool> visited(N, false);
    vector<int> dist(N, INF);

    set<pair<int, int>> st;

    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {

        auto node = *st.begin();

        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if (visited[v])
            continue;

        visited[v] = true;

        for (auto adj : graph[v])
        {

            int adj_v = adj.first;
            int dist_adj = adj.second;

            if (dist[v] + dist_adj < dist[adj_v])
            {
                dist[adj_v] = dist[v] + dist_adj;
                st.insert({dist[adj_v], adj_v});
            }
        }
    }

    cout<<dist[destination];

    // for (int i = 1; i < n; i++)
    // {
    //     cout << dist[i] << endl;
    // }
}

int main()
{

    int n;
    cin >> n;

    int src;
    int des;

    cin >> src;
    cin >> des;

    map<int, int> m;
    int arr[n];

    for(int i=0; i<n; i++){
        
        int curr;
        cin >> curr;
        arr[i] = curr;
        m.insert({curr, i});
    }


    for (int i = 0; i < n-1; i++)
    {
        int x, y, w;
        
        x = i;
        y = i+1;
        w = arr[i];

        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    graph[n].push_back({0, arr[n-1]});
    graph[0].push_back({n, arr[n-1]});



    dijkastra(src, n, des);

    return 0;
}
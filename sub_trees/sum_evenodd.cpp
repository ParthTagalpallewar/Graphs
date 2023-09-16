#include<bits/stdc++.h>
using namespace std;
const int N = 10e5+10;
vector<int> graph[N];

int sum[N], even_odd[N];

void dfs(int vertex, int par=0){
    sum[vertex] += vertex;
    if((vertex&1) == 0) even_odd[vertex] += 1;
    for(int child: graph[vertex]){
        if(child == par) continue;
        dfs(child, vertex);

        sum[vertex] += sum[child];
        even_odd[vertex] += even_odd[child];
    }
}

int main(){

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {

        int u, v, d;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout << sum[i] << " " << even_odd[i] << endl;
    }

    return 0;
}
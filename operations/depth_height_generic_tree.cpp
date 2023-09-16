#include<bits/stdc++.h>
using namespace std;
const int N = 10e5 + 10;

vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex, int par=0){

    //operation on vertex after entering

    for(int child: g[vertex]){

        //operation before entering child node

        if(child == par) continue;

        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);

        //operation after exiting child node
        height[vertex] = max(height[vertex], height[child]+1);
    }

    //operation after exiting vertex

}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout << depth[i] << " " << height[i] << endl;
    }

    return 0;
}
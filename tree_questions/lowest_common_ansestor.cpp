#include<bits/stdc++.h>
using namespace std;
const int N = 10e5 + 10;

vector<int> graph[N];
int parent[N];

void dfs(int v, int par=-1){
    parent[v] = par;
    for(int child: graph[v]){
        if(child == par) continue;

        dfs(child, v);

    }
}

vector<int> path(int v){
    vector<int> ans;

    while(v != -1){
        ans.push_back(v);
        v = parent[v];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main(){

    int n;
    std::cin >> n;

    for(int i=0; i<n-1; i++){
        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    int u, v;
    cin >> u >> v;

    vector<int> u_path = path(u);
    vector<int> v_path = path(v);

    int min_len = min(u_path.size(), v_path.size());
    int ans = 0;

    for(int i=0; i<min_len; i++){
        if(u_path[i] == v_path[i]){
            ans = u_path[i];
            continue;
        }

        break;
    }

    cout << ans << endl;


    return 0;
}
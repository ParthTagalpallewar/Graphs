#include<bits/stdc++.h>
using namespace std;

const int N = 10e5+10;
const int mod = 10e9+7;

vector<int> graph[N];
int sub_tree_sum[N];
int val[N];

void dfs(int v, int par){

    sub_tree_sum[v] += val[v];

    for(int child: graph[v]){
        if(child == par) continue;

        dfs(child, v);

        sub_tree_sum[v] += sub_tree_sum[child];
    }

}


int main(){

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    long long ans = 0;

    for(int i=2; i<=n; i++){
        int part1 = sub_tree_sum[i];
        int part2 = sub_tree_sum[1]-part1;

        ans = max(ans, (part1 * 1ll * part2)%mod);
    }

    return 0;
}
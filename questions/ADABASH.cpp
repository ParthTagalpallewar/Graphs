#include<bits/stdc++.h>
using namespace std;

const int N = 700;
vector<int> gh[N];
bool visited[N];

void dfs(int v){
    visited[v] = true;
    
    for(int child: gh[v]){
        
        if(visited[child]) continue;

        dfs(child);
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        gh[a].push_back(b);
        gh[b].push_back(a);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        dfs(i);
        ans += 1;
    }
    
    cout << ans << endl;

    return 0;
}
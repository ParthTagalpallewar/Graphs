#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[200001][2];

int treeMatching(int vertex, int isIncluded, vector<vector<int>> &adj, int par){

    //memorization
    if(dp[vertex][isIncluded] != -1){
        return dp[vertex][isIncluded];
    }

    if(isIncluded){

        int ans = 0; //if root is included and we are including all neighbor
        for(int neig: adj[vertex]){ 
            if(neig != par){
                ans += treeMatching(neig, 1, adj, vertex);
            }
        }

        int myans = 0;
        for(int neigh: adj[vertex]){
            if(neigh != par){
                myans = max(myans, ans - dp[neigh][1] + 1 + treeMatching(neigh, 0, adj, vertex));
            }
        }

        dp[vertex][isIncluded] = myans;
        return myans;
    }else{

        int ans = 0; // if root is included and we are including all neighbor
        for (int neig : adj[vertex])
        {
            if(neig != par){
                int a = treeMatching(neig, 1, adj, vertex);
                ans += max(a, treeMatching(neig, 0, adj, vertex));
            }
            
        }

        dp[vertex][isIncluded] = ans;
        return ans;
    }


}

signed main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    memset(dp, -1, sizeof(dp));

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    cout << max(treeMatching(1, 0, adj, -1), treeMatching(1, 1, adj, -1)) << endl;
}
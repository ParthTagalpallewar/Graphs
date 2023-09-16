#include<bits/stdc++.h>
using namespace std;
const int N = 2*10e5+10;
int dist = 0;
int h[N], d[N];


void height(int vertex, int par, vector<vector<int>> &adj){

    int max1 = 0;
    int max2 = 0;


    for(int child:adj[vertex]){
        if(child != par){
            
            height(child, vertex, adj);

            h[vertex] = max(h[vertex], h[child]+1);

            if(h[vertex] >= max1){
                max2 = max1;
                max1 = h[vertex];
            }else if(h[vertex] < max1 && h[vertex] > max2){
                max2 = h[vertex];
            }
        }
    }
    cout << max1 << " " << max2 << endl;
    if(max1 == 4 && max2 == 4){
        cout << vertex << " 4" << endl;
    }

    d[vertex] = max1 + max2;
    dist = max(d[vertex], dist);
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    
    for(int i=1; i<n; i++){

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    height(1, -1, adj);

    cout << dist << endl;

    return 0;
};
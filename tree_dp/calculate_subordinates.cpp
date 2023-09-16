#include<bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1674 
const int N = 2*10e5 + 10;
int dp[N];
vector<int> tree[N];

void dfs(int vertex){

    for(int child: tree[vertex]){
        dfs(child);

        dp[vertex] += dp[child]+1;
    }

}

int main(){

    int n;
    cin >> n;

    for(int i=2; i<=n; i++){
        int head;
        cin >> head;

        tree[head].push_back(i);
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 10e3+10;
vector<pair<int, int>> graph[N];

int main(){

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {

        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w}); 
    }
}
#include<bits/stdc++.h>
using namespace std;

const int N = 10e3+10;
vector<pair<int, int>> graph[N];
bool visited[N];

void dfs(pair<int, int> vertex){

    visited[vertex.first] = true;
    cout << vertex.first << " ";

    for(pair<int, int> curr: graph[vertex.first]){
        if(visited[curr.first]) continue;

        dfs(curr);
    }



}

void print(){

    for(int i=1; i<=5; i++){
        vector<pair<int, int>> current = graph[i];
        cout << i << " : " ;
        for(pair<int, int> data: current){
            cout<< data.first << " ";
        }

        cout << endl;
    }

}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});

    }
    print();
    dfs({1, 0});
}
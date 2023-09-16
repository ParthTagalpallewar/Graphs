#include <bits/stdc++.h>
using namespace std;

const int N = 10e3 + 10;
vector<int> graph[N];
int level[N];

void bfs(int source){
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout<<"curr " << curr <<" " << level[curr] <<endl;

        for(int child: graph[curr]){
            //cout << "for " << curr << " child " << child << endl;
            if(visited[child] == true) continue;

            q.push(child);
            visited[child] = true;
            level[child] = level[curr] + 1;
        }

    }
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    bfs(1);
}
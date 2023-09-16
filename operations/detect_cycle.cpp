#include <bits/stdc++.h>
using namespace std;

const int N = 10e3 + 10;
vector<pair<int, int>> graph[N];
bool visited[N];
bool is_cycle = false;

bool has_cycle(pair<int, int> vertex, pair<int, int> prev)
{

    visited[vertex.first] = true;
    cout << vertex.first << " ";

    for (pair<int, int> curr : graph[vertex.first])
    {
        if (visited[curr.first] && curr.first == prev.first) continue;

        if(visited[curr.first]) return true;

        is_cycle |= has_cycle(curr, vertex);
    }

    return has_cycle;
    
}

void print()
{

    for (int i = 1; i <= 5; i++)
    {
        vector<pair<int, int>> current = graph[i];
        cout << i << " : ";
        for (pair<int, int> data : current)
        {
            cout << data.first << " ";
        }

        cout << endl;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    print();
    //has_cycle({1, 0}, {0, 0});
    cout << (has_cycle({1, 0}, {0, 0}) ? "Cycle" : "Dont have cycle") << endl;
}
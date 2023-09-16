#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 1e9+10;

int val[N][N];
int lev[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> adj = {
    {0, 1}, {1, 1},
    {1, 0}, {1, -1},
    {0, -1}, {-1, -1},
    {-1, 0}, {-1, 1}

};

bool is_valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;

    return true;
}

int bfs(){
    int curr_max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           curr_max = max(curr_max, val[i][j]);
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           if(val[i][j] != curr_max) continue;

           q.push({i, j});
           vis[i][j] = true;
           lev[i][j] = 0;
        }
    }

    int ans = 0;

    while(!q.empty()){

        pair<int, int> curr = q.front();
        q.pop();
        
        for(pair<int, int> neigh: adj){

            int x = neigh.first + curr.first;
            int y = neigh.second + curr.second;

            if(vis[x][y] || !is_valid(x, y)) continue;

            q.push({x, y});
            vis[x][y] = true;
            lev[x][y] = lev[curr.first][curr.second] + 1 ;

            ans = max(ans, lev[x][y]);

        }

    }

    return ans;
}

void reset(){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            val[i][j] = 0;
            lev[i][j] = INF;
            vis[i][j] = false;
        }
    }
}

int main(){

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        
        cin >> n >> m;

        reset();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr;
                cin >> curr;

                val[i][j] = curr;
            }
        }

        cout<< bfs() << endl;

    }

    return 0;
}
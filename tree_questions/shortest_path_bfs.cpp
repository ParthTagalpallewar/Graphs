#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
const int inf = 1e9+10;

bool visited[8][8];
int level[8][8];

int get_x(string position){
    return position[0] - 'a';
}
int get_y(string position){
    return position[1] - '1';
}

int is_valid(int x, int y){

    if(x < 0 || x > 7 || y < 0 || y > 7) return false;

    return true;

}

vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2},
    {-2, 1}, {-2, -1},
    {-1, -2}, {1, -2},
    {2, -1}, {2, 1}
};

int bfs(string src, string des){

    queue<pair<int, int>> q;

    int src_x = get_x(src);
    int src_y = get_y(src);
    int des_x = get_x(des);
    int des_y = get_y(des);

    level[src_x][src_y] = 0;

    visited[src_x][src_y] = true;
    q.push({src_x, src_y});

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for(pair<int, int> i: movements){

            int curr_x = x+i.first;
            int curr_y = y+i.second;

            if(!is_valid(curr_x, curr_y) || visited[curr_x][curr_y]) continue;

            q.push({curr_x, curr_y});
            visited[curr_x][curr_y] = true;

            level[curr_x][curr_y] = level[x][y]+1;

            if(curr_x == des_x && curr_y == des_y){
                return level[curr_x][curr_y];
            }

        }
        

    }

    return level[des_x][des_y];


}

void clear(){
    for(int i=0; i < 8; i++){
        for(int j=0; j<8; j++){
            visited[i][j] = false;
            level[i][j] = inf;
        }
    }
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        clear();
        string src, des;
        cin >> src >> des;

        int ans =  bfs(src, des);
        cout << ans << endl;
    }
    return 0;
}
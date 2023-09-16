#include<bits/stdc++.h>
using namespace std;

/*  Finding Diameter of tree (longest distance between tow nodes)

    Approach:- finding one end - one end can be find just by finding longest distance 
                                    from any node

                finding second end - do dfs on root finded in step 1 and you will get diameter
*/

const int N = 10e5+10;
vector<int> graph[N];

int depth[N];

void dfs(int v, int par=-1){

    for(int child: graph[v]){
        if(child == par) continue;

        depth[child] = depth[v]+1;

        dfs(child, v);
    }

}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    int max_depth = -1;
    int max_depth_node;

    for(int i=1; i<=n; i++){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0;
    }

    dfs(max_depth_node);

    max_depth = -1;
    for(int i=1; i<=n; i++){
        max_depth = max(max_depth, depth[i]);
    }

    std::cout << max_depth << endl;
   

    return 0;
}
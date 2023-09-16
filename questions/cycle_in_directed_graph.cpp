//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int v, vector<int> graph[], vector<bool> &visited, vector<bool> &recS)
    {

        visited[v] = true;
        recS[v] = true;

        for (int adj : graph[v])
        {

            if (!visited[adj])
            {
                if (dfs(adj, graph, visited, recS))
                {
                    return true;
                }
            }

            else
            {
                if (recS[adj])
                    return true;
            }
        }

        recS[v] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> graph[])
    {

        vector<bool> visited(V, false);
        vector<bool> recS(V, false);

        bool ans = false;

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
            {
                if (dfs(i, graph, visited, recS) == true)
                {
                    ans = true;
                    break;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";


    return 0;
}

// } Driver Code Ends
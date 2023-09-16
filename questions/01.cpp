#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph;
int longest = 0;


int get_longest_path(int i, int j, int prev, vector<vector<int>> &dp)
{

    int n = graph.size();
    int m = graph[0].size();

    if (i < 0 || j < 0)
        return 0;
    if (i >= n || j >= m)
        return 0;

    if (graph[i][j] - prev != 1)
        return 0;

    char ch = graph[i][j];

    if(dp[i][j] != -1) return dp[i][j]+1;

    int gretest = get_longest_path(i - 1, j, ch, dp);

    gretest = max(gretest, get_longest_path(i + 1, j, ch, dp));
    gretest = max(gretest, get_longest_path(i, j - 1, ch, dp));
    gretest = max(gretest, get_longest_path(i, j + 1, ch, dp));
    gretest = max(gretest, get_longest_path(i - 1, j + 1, ch, dp));
    gretest = max(gretest, get_longest_path(i - 1, j - 1, ch, dp));
    gretest = max(gretest, get_longest_path(i + 1, j - 1, ch, dp));
    gretest = max(gretest, get_longest_path(i + 1, j + 1, ch, dp));

    dp[i][j] = gretest;

    return gretest + 1;
}

int main()
{
    int k = 0;

    while (1)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string curr;
            cin >> curr;

            graph.push_back(curr);
        }

        vector<vector<int>> dp(n+10, vector<int>(m+10, -1));

        int x, y;
        cin >> x >> y;
        int longest = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(graph[i][j] == 'A')
                    longest = max(longest, get_longest_path(i, j, graph[i][j] - 1, dp));
            }
        }

        cout << "Case " << ++k << ": " << longest << endl;
        if (x == 0 && y == 0)
            break;
    }
}
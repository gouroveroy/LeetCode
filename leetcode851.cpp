#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> adj;
    vector<int> quiet;
    vector<int> dp;

    int dfs(int node)
    {
        if (dp[node] != -1)
        {
            return dp[node];
        }

        dp[node] = node;
        for (int neighbor : adj[node])
        {
            int candidate = dfs(neighbor);
            if (quiet[candidate] < quiet[dp[node]])
            {
                dp[node] = candidate;
            }
        }
        return dp[node];
    }

public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        this->quiet = quiet;
        adj.resize(n);

        for (auto &r : richer)
        {
            adj[r[1]].push_back(r[0]);
        }

        dp.assign(n, -1);
        vector<int> answer(n);

        for (int i = 0; i < n; i++)
        {
            answer[i] = dfs(i);
        }
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> richer = {{0, 1}};
    vector<int> quiet = {0, 1};
    vector<int> result = sol.loudAndRich(richer, quiet);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

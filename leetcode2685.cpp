#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> parent(n), size(n, 1), edgeCount(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        function<int(int)> find = [&](int i) -> int
        {
            if (parent[i] == i)
            {
                return i;
            }
            else
            {
                return parent[i] = find(parent[i]);
            }
        };

        for (auto &edge : edges)
        {
            int a = find(edge[0]);
            int b = find(edge[1]);
            if (a != b)
            {
                if (size[a] < size[b])
                {
                    parent[a] = b;
                    size[b] += size[a];
                    edgeCount[b] += (edgeCount[a] + 1);
                }
                else
                {
                    parent[b] = a;
                    size[a] += size[b];
                    edgeCount[a] += (edgeCount[b] + 1);
                }
            }
            else
            {
                edgeCount[a]++;
            }
        }

        int completeConnectedComponentCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                int nodeCount = size[i];
                int edgeCnt = edgeCount[i];
                if ((edgeCnt * 2) == (nodeCount * (nodeCount - 1)))
                {
                    completeConnectedComponentCount++;
                }
            }
        }
        return completeConnectedComponentCount;
    }
};

int main()
{
    Solution s;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {4, 5}};
    cout << s.countCompleteComponents(n, edges) << endl;
    return 0;
}

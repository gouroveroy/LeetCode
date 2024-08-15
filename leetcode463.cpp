#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int p = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }
                int close = 0;
                if (j > 0 && grid[i][j - 1])
                {
                    close++;
                }
                if (j < grid[i].size() - 1 && grid[i][j + 1])
                {
                    close++;
                }
                if (i > 0 && grid[i - 1][j])
                {
                    close++;
                }
                if (i < grid.size() - 1 && grid[i + 1][j])
                {
                    close++;
                }
                p += (4 - close);
            }
        }
        return p;
    }
};

int main()
{
    // vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    vector<vector<int>> grid = {{1, 0}};
    // vector<vector<int>> grid = {{1}};
    Solution obj;
    cout << obj.islandPerimeter(grid) << endl;
    return 0;
}

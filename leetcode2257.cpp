#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print(vector<vector<char>> &grid)
    {
        for (auto &v : grid)
        {
            for (char &c : v)
            {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        unordered_map<string, int> mp = {
            {"UNGUARDED", 0}, {"GUARDED", 1}, {"GUARD", 2}, {"WALL", 3}};
        vector<vector<int>> grid(m, vector<int>(n, mp["UNGUARDED"]));

        for (auto &v : guards)
        {
            grid[v[0]][v[1]] = mp["GUARD"];
        }
        for (auto &v : walls)
        {
            grid[v[0]][v[1]] = mp["WALL"];
        }
        for (auto &v : guards)
        {
            for (int i = v[0] + 1; i < m; i++)
            {
                if (grid[i][v[1]] == mp["UNGUARDED"] or
                    grid[i][v[1]] == mp["GUARDED"])
                {
                    grid[i][v[1]] = mp["GUARDED"];
                }
                else
                {
                    break;
                }
            }
            for (int i = v[0] - 1; i >= 0; i--)
            {
                if (grid[i][v[1]] == mp["UNGUARDED"] or
                    grid[i][v[1]] == mp["GUARDED"])
                {
                    grid[i][v[1]] = mp["GUARDED"];
                }
                else
                {
                    break;
                }
            }
            for (int i = v[1] + 1; i < n; i++)
            {
                if (grid[v[0]][i] == mp["UNGUARDED"] or
                    grid[v[0]][i] == mp["GUARDED"])
                {
                    grid[v[0]][i] = mp["GUARDED"];
                }
                else
                {
                    break;
                }
            }
            for (int i = v[1] - 1; i >= 0; i--)
            {
                if (grid[v[0]][i] == mp["UNGUARDED"] or
                    grid[v[0]][i] == mp["GUARDED"])
                {
                    grid[v[0]][i] = mp["GUARDED"];
                }
                else
                {
                    break;
                }
            }
        }
        int count = 0;
        for (auto &v : grid)
        {
            for (int &c : v)
            {
                if (c == mp["UNGUARDED"])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    cout << s.countUnguarded(4, 6, guards, walls) << endl;
    return 0;
}

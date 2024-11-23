#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print(vector<vector<char>> &box)
    {
        for (int i = 0; i < box.size(); i++)
        {
            for (int j = 0; j < box[0].size(); j++)
            {
                cout << box[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> clockwise(n, vector<char>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                clockwise[j][m - i - 1] = box[i][j];
            }
        }
        vector<int> dotCount(m, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                if (clockwise[i][j] == '.')
                {
                    dotCount[j]++;
                }
                else if (clockwise[i][j] == '*')
                {
                    dotCount[j] = 0;
                }
                else
                {
                    if (dotCount[j])
                    {
                        clockwise[i + dotCount[j]][j] = '#';
                        clockwise[i][j] = '.';
                    }
                }
            }
        }
        return clockwise;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> box = {{'#', '#', '*', '.', '*', '.'},
                                {'#', '#', '#', '*', '.', '.'},
                                {'#', '#', '#', '.', '#', '.'}};
    vector<vector<char>> ans = s.rotateTheBox(box);
    s.print(ans);
    return 0;
}

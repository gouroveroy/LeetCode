#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> row, index;
        int i = 0;
        for (auto &v : mat)
        {
            row.push_back(count(v.begin(), v.end(), 1));
            index.push_back(i++);
        }
        sort(index.begin(), index.end(), [&row](int a, int b) -> bool
             {
            if (row[a] < row[b])
            {
                return true;
            }
            else if (row[a] > row[b])
            {
                return false;
            }
            else
            {
                return a < b;
            } });
        return vector<int>(index.begin(), index.begin() + k);
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    int k = 3;
    Solution obj;
    for (int i : obj.kWeakestRows(mat, k))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        for (int n : nums)
        {
            if (n < k)
            {
                return -1;
            }
            else if (n > k)
            {
                s.insert(n);
            }
        }
        return s.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {9, 10, 9, 7, 8, 8, 7, 6, 7, 8, 10, 9, 8, 10, 7};
    int k = 7;
    cout << s.minOperations(nums, k) << endl;
    return 0;
}
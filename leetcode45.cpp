#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        int steps = 0;
        int maxReach = 0;
        int lastReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > lastReach)
            {
                lastReach = maxReach;
                steps++;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return steps;
    }
};

int main()
{
    vector<int> nums = {3, 3, 1, 2, 1, 4, 5};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}

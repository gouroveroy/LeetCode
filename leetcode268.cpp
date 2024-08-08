#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (nums.size() * (nums.size() + 1)) / 2 - sum;
    }
};

int main()
{
    vector<int> nums = {0, 1, 3};
    Solution obj;
    cout << obj.missingNumber(nums) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int subArraySum(vector<int> &nums, int k, int p)
    {
        int length = nums.size();
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum = (currSum + nums[i]) % p;
            int need = (currSum - k + p) % p;
            if (prefixSum.find(need) != prefixSum.end())
            {
                length = min(length, i - prefixSum[need]);
            }
            prefixSum[currSum] = i;
        }
        return length;
    }

public:
    int minSubarray(vector<int> &nums, int p)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int remainSum = sum % p;
        if (remainSum == 0)
        {
            return 0;
        }
        int length = subArraySum(nums, remainSum, p);
        return length == nums.size() ? -1 : length;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
    int p = 26;
    // cout << accumulate(nums.begin(), nums.end(), 0LL) % p << endl;
    cout << s.minSubarray(nums, p) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start < end - 1)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (target <= nums[start])
        {
            return start;
        }
        else if (target > nums[start] && target < nums[end])
        {
            return start + 1;
        }
        return end + !(target == nums[end]);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 7;
    Solution obj;
    cout << obj.searchInsert(nums, target) << endl;
    return 0;
}

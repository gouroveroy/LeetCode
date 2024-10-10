#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums[0] == nums[nums.size() - 1])
        {
            return 1 + (nums.size() > 1);
        }
        int first = 0;
        int dest = first;
        int count = 1;
        while (++first < nums.size())
        {
            if (nums[first] != nums[dest])
            {
                nums[++dest] = nums[first];
                count = 1;
            }
            else
            {
                if (count + 1 <= 2)
                {
                    count++;
                    nums[++dest] = nums[first];
                }
            }
        }
        return ++dest;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3};
    reverse(nums.begin(), nums.end());
    Solution s;
    int size = s.removeDuplicates(nums);
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}

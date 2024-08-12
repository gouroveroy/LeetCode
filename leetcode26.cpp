#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // way - 1
        // auto it = unique(nums.begin(), nums.end());
        // return distance(nums.begin(), it);
        // way - 2
        if (nums[0] == nums[nums.size() - 1])
        {
            return 1;
        }
        int first = 0;
        int next = first;
        while (++next < nums.size())
        {
            if (nums[first] == nums[next])
            {
                break;
            }
            first = next;
        }
        int dest = first;
        ++first;
        while (++first < nums.size())
        {
            if (nums[first] != nums[dest])
            {
                nums[++dest] = nums[first];
            }
        }
        return ++dest;
    }
};

int main()
{
    return 0;
}

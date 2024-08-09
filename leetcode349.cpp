#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> intersections;
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        auto it1 = set1.begin();
        auto it2 = set2.begin();
        while (it1 != set1.end() && it2 != set2.end())
        {
            if (*it1 < *it2)
            {
                it1++;
            }
            else if (*it1 > *it2)
            {
                it2++;
            }
            else
            {
                intersections.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return intersections;
    }
};

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    Solution obj;
    for (int n : obj.intersection(nums1, nums2))
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

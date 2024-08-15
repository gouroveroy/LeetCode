#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        nums1.resize(m + n);
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 3, 6};
    vector<int> nums2 = {2, 4, 5};
    Solution obj;
    obj.merge(nums1, nums1.size(), nums2, nums2.size());
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}

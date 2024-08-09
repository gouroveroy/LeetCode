#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        vector<int> answer;
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = abs(sum1 - sum2);
        if (sum1 > sum2)
        {
            int i = 0, j = 0;
            while (i < aliceSizes.size() && j < bobSizes.size())
            {
                if (aliceSizes[i] - bobSizes[j] == diff / 2)
                {
                    answer.push_back(aliceSizes[i]);
                    answer.push_back(bobSizes[j]);
                    break;
                }
                else if (aliceSizes[i] - bobSizes[j] > diff / 2)
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            int i = 0, j = 0;
            while (i < aliceSizes.size() && j < bobSizes.size())
            {
                if (bobSizes[j] - aliceSizes[i] == diff / 2)
                {
                    answer.push_back(aliceSizes[i]);
                    answer.push_back(bobSizes[j]);
                    break;
                }
                else if (bobSizes[j] - aliceSizes[i] > diff / 2)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        return answer;
    }
};

int main()
{
    vector<int> aliceSizes = {1, 2};
    vector<int> bobSizes = {2, 3};
    Solution obj;
    cout << obj.fairCandySwap(aliceSizes, bobSizes)[0] << " " << obj.fairCandySwap(aliceSizes, bobSizes)[1] << endl;
    return 0;
}

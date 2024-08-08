#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        float start = 0, end = x;
        // cout << start << " " << end << endl;
        while (end - start > 0.1)
        {
            float mid = (start + end) / 2;
            // cout << mid << endl;
            if ((int)(mid * mid) == x)
            {
                return (int)mid;
            }
            else if (mid * mid < (float)x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return (int)start;
    }
};

int main()
{
    int x = 8;
    Solution obj;
    cout << obj.mySqrt(x) << endl;
    return 0;
}

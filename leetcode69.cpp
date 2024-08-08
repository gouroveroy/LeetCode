#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int start = 0, end = x;
        while (end - start > 5)
        {
            int mid = (start + end) / 2;
            if (mid == x / mid)
            {
                return mid;
            }
            else if (mid < x / mid)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        int sqrt = 0;
        for (int i = start; i <= end; i++)
        {
            if (i == 0)
            {
                continue;
            }
            if (i >= x / i)
            {
                sqrt = i - (i == x / i ? 0 : 1);
                break;
            }
        }
        return sqrt;
    }
};

int main()
{
    int x = (1 << 10) - 1;
    cout << x << endl;
    Solution obj;
    cout << obj.mySqrt(x) << endl;
    return 0;
}

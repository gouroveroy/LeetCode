#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int count = 0;
        int f = 0, l = 0;
        int zero = 0, one = 0;
        while (l < s.size())
        {
            if (s[l] == '0')
            {
                if (zero > 0 && one > 0 && s[l - 1] == '1')
                {
                    f += zero;
                    count += min(zero, one);
                    zero = 0;
                }
                zero++;
            }
            else
            {
                if (zero > 0 && one > 0 && s[l - 1] == '0')
                {
                    f += one;
                    count += min(zero, one);
                    one = 0;
                }
                one++;
            }
            l++;
        }
        count += min(zero, one);
        return count;
    }
};

int main()
{
    string s = "10101";
    Solution obj;
    cout << obj.countBinarySubstrings(s) << endl;
    return 0;
}

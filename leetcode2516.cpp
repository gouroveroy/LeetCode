#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        if (k == 0)
            return 0;
        map<char, int> count;
        int l = 0, r = s.size() - 1;
        while (r >= 0)
        {
            count[s[r]]++;
            if (count['a'] >= k and count['b'] >= k and count['c'] >= k)
            {
                break;
            }
            r--;
        }
        if (r < 0)
            return -1;
        int minMinute = s.size() - r;

        while (l < s.size())
        {
            if (s[l] == s[r])
            {
                r++;
                while (count[s[r]] > k)
                {
                    count[s[r]]--;
                    r++;
                }
            }
            else
            {
                count[s[l]]++;
            }
            minMinute = min(minMinute, static_cast<int>(s.size()) - r + l + 1);
            l++;
        }
        return minMinute;
    }
};

int main()
{
    Solution s;
    string str = "aabaaaacaabc";
    int k = 2;
    cout << s.takeCharacters(str, k) << endl;
    return 0;
}

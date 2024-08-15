#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int number = m[s[s.size() - 1]];
        int i = s.size() - 2;
        while (i >= 0)
        {
            if (m[s[i]] < m[s[i + 1]])
            {
                number -= m[s[i]];
                i--;
                continue;
            }
            number += m[s[i]];
            i--;
        }
        return number;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution obj;
    cout << obj.romanToInt(s) << endl;
    return 0;
}

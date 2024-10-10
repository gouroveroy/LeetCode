#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void reverseWord(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

public:
    string reverseWords(string s)
    {
        while (!s.empty() && isspace(s.back()))
        {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        while (!s.empty() && isspace(s.back()))
        {
            s.pop_back();
        }
        int n = s.size();
        int i = 0, j = 1;
        while (j <= n)
        {
            if (isspace(s[i]))
            {
                i++;
                j++;
            }
            else if (j == n or isspace(s[j]))
            {
                reverseWord(s, i, j - 1);
                i = j + 1;
                j = i + 1;
            }
            else
            {
                j++;
            }
        }
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != ' ')
            {
                s[index++] = s[i];
            }
            else if (s[i - 1] != ' ')
            {
                s[index++] = ' ';
            }
        }
        if (index > 0 && s[index - 1] == ' ')
        {
            index--;
        }
        s.resize(index);
        return s;
    }
};

int main()
{
    string s = "    the          sky         is                     blue";
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    return 0;
}

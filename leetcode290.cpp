#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> split(string s, char del)
    {
        vector<string> sp;
        string temp = "";
        for (const char &c : s)
        {
            if (c == ' ')
            {
                sp.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(c);
            }
        }
        sp.push_back(temp);
        return sp;
    }

    bool wordPattern(string pattern, string s)
    {
        vector<string> sp = split(s, ' ');
        if (sp.size() != pattern.size())
        {
            return false;
        }
        map<char, string> m;
        map<string, char> r;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (m.find(pattern[i]) != m.end())
            {
                if (m[pattern[i]] != sp[i])
                {
                    return false;
                }
            }
            else if (r.find(sp[i]) != r.end())
            {
                if (r[sp[i]] != pattern[i])
                {
                    return false;
                }
            }
            else
            {
                m[pattern[i]] = sp[i];
                r[sp[i]] = pattern[i];
            }
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution obj;
    cout << obj.wordPattern(pattern, s) << endl;
    return 0;
}

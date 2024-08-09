#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int start = 0, end = letters.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (letters[mid] <= target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start < letters.size() ? letters[start] : letters[0];
    }
};

int main()
{
    vector<char> letters = { 'c', 'f', 'j'};
    char target = 'j';
    Solution obj;
    cout << obj.nextGreatestLetter(letters, target) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        stack<int> s;
        queue<int> q;
        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            s.push(i);
        }
        for (int i = 0; i < students.size(); i++)
        {
            q.push(i);
        }
        int size = 0;
        while (!q.empty() || !s.empty())
        {
            if (size == q.size())
            {
                break;
            }
            if (students[q.front()] == sandwiches[s.top()])
            {
                s.pop();
                q.pop();
                size = (size != 0 ? 0 : size);
            }
            else
            {
                size++;
                q.push(q.front());
                q.pop();
            }
        }
        return size;
    }
};

int main()
{
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    Solution obj;
    cout << obj.countStudents(students, sandwiches) << endl;
    return 0;
}

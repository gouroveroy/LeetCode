#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        vector<pair<int, int>> arrival, leaving;
        for (int i = 0; i < times.size(); i++)
        {
            arrival.push_back({times[i][0], i});
            leaving.push_back({times[i][1], i});
        }
        sort(arrival.begin(), arrival.end());
        sort(leaving.begin(), leaving.end());
        int a = 0, l = 0;
        int chair = 0;
        map<int, int> friendToChair;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> friendNo(times.size(), -1);
        while (a < times.size())
        {
            if (arrival[a].first < leaving[l].first)
            {
                if (pq.empty())
                {
                    friendNo[chair] = arrival[a].second;
                    friendToChair[arrival[a].second] = chair;
                    chair++;
                }
                else
                {
                    friendNo[pq.top()] = arrival[a].second;
                    friendToChair[arrival[a].second] = pq.top();
                    pq.pop();
                }
                if (arrival[a].second == targetFriend)
                {
                    break;
                }
                a++;
            }
            else if (arrival[a].first == leaving[l].first)
            {
                int index = 1;
                for (int i = l + 1; i < times.size(); i++)
                {
                    if (leaving[i].first == leaving[i - 1].first)
                    {
                        index++;
                    }
                    else
                    {
                        break;
                    }
                }
                sort(leaving.begin() + l, leaving.begin() + l + index,
                     [&friendToChair](pair<int, int> a, pair<int, int> b)
                     {
                         return friendToChair[a.second] <
                                friendToChair[b.second];
                     });
                friendNo[friendToChair[leaving[l].second]] = -1;
                pq.push(friendToChair[leaving[l].second]);
                friendNo[pq.top()] = arrival[a].second;
                friendToChair[arrival[a].second] = pq.top();
                pq.pop();
                if (arrival[a].second == targetFriend)
                {
                    break;
                }
                a++;
                l++;
            }
            else
            {
                int index = 1;
                for (int i = l + 1; i < times.size(); i++)
                {
                    if (leaving[i].first == leaving[i - 1].first)
                    {
                        index++;
                    }
                    else
                    {
                        break;
                    }
                }
                sort(leaving.begin() + l, leaving.begin() + l + index,
                     [&friendToChair](pair<int, int> a, pair<int, int> b)
                     {
                         return friendToChair[a.second] <
                                friendToChair[b.second];
                     });
                friendNo[friendToChair[leaving[l].second]] = -1;
                pq.push(friendToChair[leaving[l].second]);
                l++;
            }
        }
        return friendToChair[targetFriend];
    }
};

int main()
{
    vector<vector<int>> times = {{4, 5}, {6, 8}, {8, 10}, {1, 8}};
    int targetFriend = 2;
    Solution s;
    cout << s.smallestChair(times, targetFriend) << endl;
    return 0;
}

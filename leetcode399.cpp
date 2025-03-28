#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        unordered_map<string, int> node;
        int n = 0;
        for (auto &v : equations)
        {
            if (node.find(v[0]) == node.end())
            {
                node[v[0]] = n++;
            }
            if (node.find(v[1]) == node.end())
            {
                node[v[1]] = n++;
            }
        }

        vector<vector<long double>> graph(n, vector<long double>(n, -1.0));
        for (int i = 0; i < n; i++)
        {
            graph[i][i] = 1.0;
        }

        for (int i = 0; i < values.size(); i++)
        {
            int u = node[equations[i][0]];
            int v = node[equations[i][1]];
            long double w = values[i];
            graph[u][v] = w;
            graph[v][u] = 1.0 / w;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][k] != -1.0 and graph[k][j] != -1.0)
                    {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> answer;

        for (auto &q : queries)
        {
            if (node.find(q[0]) == node.end() || node.find(q[1]) == node.end())
            {
                answer.push_back(-1.0);
            }
            else
            {
                int u = node[q[0]];
                int v = node[q[1]];
                if (graph[u][v] == -1.0)
                {
                    answer.push_back(-1.0);
                }
                else
                {
                    answer.push_back(graph[u][v]);
                }
            }
        }
        return answer;
    }
};

/*
input:
[["b","a"],["c","b"],["d","c"],["e","d"],["f","e"],["g","f"],["h","g"],["i","h"],["j","i"],["k","j"],["k","l"],["l","m"],["m","n"],["n","o"],["o","p"],["p","q"],["q","r"],["r","s"],["s","t"],["t","u"]]
[1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05]
[["a","u"]]
output: [0.99994]
expected: [1.00000]
*/

int main()
{
    Solution s;
    vector<vector<string>> equations = {{"b","a"}, {"c", "b"}, {"d", "c"}, {"e", "d"}, {"f", "e"}, {"g", "f"}, {"h", "g"}, {"i", "h"}, {"j", "i"}, {"k", "j"}, {"k", "l"}, {"l", "m"}, {"m", "n"}, {"n", "o"}, {"o", "p"}, {"p", "q"}, {"q", "r"}, {"r", "s"}, {"s", "t"}, {"t", "u"}};
    vector<double> values = {1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05};
    vector<vector<string>> queries = {{"a", "u"}};
    vector<double> result = s.calcEquation(equations, values, queries);
    for (double r : result)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}

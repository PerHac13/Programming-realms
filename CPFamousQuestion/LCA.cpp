#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
vector<int> g[N], p(N);

void dfs(int vertex, int par = 0)
{
    p[vertex] = par;

    for (int child : g[vertex])
    {
        if (child == par)
            continue;

        dfs(child, vertex);
    }
}
vector<int> path(int v)
{
    vector<int> ans;
    while (v != 0)
    {
        ans.push_back(v);
        v = p[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n, e;
    cin >> n;
    // cout << "b";
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mn_ln = min(path_x.size(), path_y.size());
    int lca = -1;
    for (int i = 0; i < mn_ln; ++i)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }
        else
            break;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
vector<bool> vis(N);
vector<int> g[N];
vector<vector<int>> cc;
vector<int> curCC;
void dfs(int vertex)
{

    vis[vertex] = true;
    curCC.push_back(vertex);
    for (int child : g[vertex])
    {
        if (vis[child])
            continue;

        dfs(child);
    }
}
bool cyclepre(int vertex, int par = 0)
{
    vis[vertex] = 1;
    bool isLoopExists = 0;

    for (int child : g[vertex])
    {
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return 1;

        isLoopExists |= cyclepre(child, vertex);
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isLoopExists = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (cyclepre(i, 0))
        {
            isLoopExists = 1;
            break;
        }
        // curCC.clear();
        // dfs(i);
        // cc.push_back(curCC);
    }
    // cout << cc.size() << endl;
    // for (auto c_cc : cc)
    // {
    //     for (int vertex : c_cc)
    //     {
    //         cout << vertex << ' ';
    //     }
    //     cout << endl;
    // }
    cout << isLoopExists << endl;

    return 0;
}
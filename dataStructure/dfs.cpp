#include <bits/stdc++.h>

using namespace std;

bool vis[1000] = {0};
vector<int> adj[10000];

void dfs(int node)
{
    // preorder
    vis[node] = 1;
    cout << node << " ";

    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
            dfs(*it);
    }
}

int main()
{

    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    return 0;
}
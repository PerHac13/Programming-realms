#include <bits/stdc++.h>

using namespace std;

bool vis[1000] = {0};
vector<int> adj[1000];

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

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                q.push(*it);
                vis[*it] = 1;
            }
        }
    }

    return 0;
}
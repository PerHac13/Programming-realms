#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int lvl[N];
vector<int> g[N];
vector<bool> vis(N);

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (int child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                lvl[child] = lvl[cur_v] + 1;
            }
        }
    }
}

int main()
{

    return 0;
}
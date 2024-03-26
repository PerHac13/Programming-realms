#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7, INF = 1e9 + 10;
vector<pair<int, int>> g[N];
int n, m;
vector<int> lvl(N, INF);

int bfs01()
{
    deque<int> q;
    q.push_back(1);
    lvl[1] = 0;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();
        for (auto child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (lvl[cur_v] + wt < lvl[child_v])
            {
                lvl[child_v] = lvl[cur_v] + wt;
                if (wt == 1)
                    q.push_back(child_v);
                else
                    q.push_front(child_v);
            }
        }
    }
    return lvl[n] == INF ? -1 : lvl[n];
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    cout << bfs01();

    return 0;
}
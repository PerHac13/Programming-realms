#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10, INF = 1e9 + 10;
vector<int> g[N];
int val[N][N], vis[N][N], lvl[N][N];
int n, m, mx;

vector<pair<int, int>> movements = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mx == val[i][j])
            {
                q.push({i, j});
                lvl[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto v = q.front();
        int v_x = v.first, v_y = v.second;
        q.pop();
        for (auto movement : movements)
        {
            int childX = movement.first + v_x;
            int childY = movement.second + v_y;
            if (!isValid(childX, childY))
                continue;
            if (vis[childX][childY])
                continue;
            q.push({childX, childY});
            lvl[childX][childY] = lvl[v_x][v_y] + 1;
            vis[childX][childY] = 1;
            ans = max(ans, lvl[childX][childY]);
        }
    }
    return ans;
}

// Question Snake (codechef) SNSOCIAL

int main()
{

    cin >> n >> m;
    mx = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> val[i][j];
            mx = max(mx, val[i][j]);
            lvl[i][j] = INF;
        }
    }
    cout << bfs() << endl;

    return 0;
}
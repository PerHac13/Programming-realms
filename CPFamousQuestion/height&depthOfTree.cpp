#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
vector<int> g[N], h(N), d(N);

void dfs(int vertex, int par = 0)
{

    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        d[child] = d[vertex] + 1;
        dfs(child, vertex);
        h[vertex] = max(h[vertex], h[child] + 1);
    }
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
    for (int i = 1; i <= n; ++i)
    {
        cout << h[i] << ' ' << d[i] << endl;
    }
    return 0;
}
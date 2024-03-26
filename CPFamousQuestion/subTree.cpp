#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;
vector<bool> vis(N);
vector<int> g[N];
int subtree_sum[N];
int subtree_evenCnt[N];

void dfs(int vertex, int par = 0)
{

    subtree_sum[vertex] += vertex;
    if (vertex % 2 == 0)
        subtree_evenCnt[vertex]++;
    for (int child : g[vertex])
    {

        if (child == par)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        subtree_evenCnt[vertex] += subtree_evenCnt[child];
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

    return 0;
}
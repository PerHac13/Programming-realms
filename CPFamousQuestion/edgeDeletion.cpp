#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7, M = 1e9 + 7;
vector<int> g[N], subtree_sum(N), val(N);

void dfs(int vertex, int par = 0)
{
    subtree_sum[vertex] += val[vertex];
    for (int child : g[vertex])
    {
        if (child == par)
            continue;

        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
    }
}
// Question We have to delete ans edge to create two tree the
//  the we calculate the sum of each tree and we have to maximize
// the the product of sum of both tree..
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
    long long ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans, (part1 * 1LL * part2) % M);
    }
    cout << ans;
    return 0;
}
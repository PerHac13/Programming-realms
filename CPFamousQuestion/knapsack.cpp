#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 1e5 + 10;
vector<int> w(N), v(N);
long long dp[105][N];

long long Knapsack01(int idx, int wt_left)
{

    if (wt_left == 0)
        return 0;
    if (idx < 0)
        return 0;
    if (dp[idx][wt_left] != -1)
        return dp[idx][wt_left];

    long long ans = Knapsack01(idx - 1, wt_left);
    if (wt_left - w[idx] >= 0)
        ans = max(ans, Knapsack01(idx - 1, wt_left - w[idx]) + v[idx]);
    return dp[idx][wt_left] = ans;
}

// TC O(N*W)
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, wt;
    cin >> n >> wt;
    f(i, 0, n) cin >> w[i] >> v[i];
    cout << Knapsack01(n - 1, wt);

    return 0;
}
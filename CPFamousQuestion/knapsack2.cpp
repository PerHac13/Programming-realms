#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 1e5 + 10;
int wt[105], val[105];
long long dp[105][100005];

long long Knapsack(int idx, int val_left)
{
    if (val_left == 0)
        return 0;
    if (idx < 0)
        return 1e15;
    if (dp[idx][val_left] != -1)
        return dp[idx][val_left];

    long long ans = Knapsack(idx - 1, val_left);
    if (val_left - val[idx] >= 0)
        ans = min(ans, Knapsack(idx - 1, val_left - val[idx]) + wt[idx]);

    return dp[idx][val_left] = ans;
}

int main()
{

    int n, w;
    cin >> n >> w;
    f(i, 0, n) cin >> wt[i] >> val[i];
    memset(dp, -1, sizeof(dp));
    int max_value = 1e5;

    for (int i = max_value; i >= 0; --i)
    {
        if (Knapsack(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
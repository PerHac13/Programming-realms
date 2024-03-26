#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 1e5 + 10;
int a[N], dp[205][20005], d[205][20005];

bool subsetSum(int idx, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (idx < 0)
        return 0;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    bool ispossible = subsetSum(idx - 1, sum);

    if (sum - a[idx] >= 0)
        ispossible |= subsetSum(idx - 1, sum - a[idx]);

    return dp[idx][sum] = ispossible;
}
int minElementsToSum(int i, long long Sum)
{
    if (Sum == 0)
        return 0;
    // if (dp[i][Sum] != -1)
    //     return d[i][Sum];
    if (Sum < 0)
        return INT_MAX - 10;
    if (i < 0)
        return INT_MAX - 10;
    int ans = 0;
    ans = minElementsToSum(i - 1, Sum);
    long long tmp = Sum - a[i];
    ans = min(ans, minElementsToSum(i - 1, tmp) + 1);
    return ans;
}
int main()
{

    memset(dp, -1, sizeof(dp));
    memset(d, -1, sizeof(d));
    int n, x;
    cin >> n >> x;
    f(i, 0, n)
    {
        cin >> a[i];
    }
    // cout << subsetSum(n - 1, x);
    if (subsetSum(n - 1, x))
    {
        cout << minElementsToSum(n - 1, x);
    }
    else
    {
        cout << minElementsToSum(n - 1, x);
    }

    return 0;
}
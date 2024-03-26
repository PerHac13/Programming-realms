#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 2510;
vector<int> dp(10010, -1);
int dpw[310][10010];

vector<int> coins;

int coinChange(int amt)
{
    if (amt == 0)
        return 0;
    if (dp[amt] != -1)
        return dp[amt];

    int ans = INT_MAX;
    for (int coin : coins)
    {
        if (amt - coin >= 0)
            ans = min(ans + 0LL, coinChange(amt - coin) + 1LL);
    }
    return dp[amt] = ans;
}
int coinChangeWays(int idx, int amt)
{
    if (amt == 0)
        return 1;
    if (idx < 0)
        return 0;
    if (dpw[idx][amt] != -1)
        return dpw[idx][amt];
    int ways = 0;
    for (int coin_amt = 0; coin_amt <= amt; coin_amt += coins[idx])
    {
        ways += coinChangeWays(idx - 1, amt - coin_amt);
    }
    return dpw[idx][amt] = ways;
}

int main()
{

    int n, k;
    cin >> n >> k;
    f(i, 0, k)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int ans = coinChange(n);
    cout << (ans == INT_MAX) ? -1 : ans;
    memset(dpw, -1, sizeof(dpw));
    cout << "\n No. of possible ways:\n";
    cout << coinChangeWays(k - 1, n);

    return 0;
}
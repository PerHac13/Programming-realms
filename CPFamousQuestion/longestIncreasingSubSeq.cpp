#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 25e2 + 10;
vector<int> a(N), dp(N, -1);

int lis(int i)
{
    int ans = 1;
    if (dp[i] != -1)
        return dp[i];
    f(j, 0, i)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}

int main()
{

    int n;
    cin >> n;
    f(i, 0, n) cin >> a[i];
    int ans = 0;
    f(i, 1, n + 1)
    {
        ans = max(ans, lis(i));
    }
    cout << ans;

    return 0;
}
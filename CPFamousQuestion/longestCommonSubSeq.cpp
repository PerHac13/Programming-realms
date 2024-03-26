#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 1e5 + 10;
string s1, s2;
int dp[1005][1005];
int lcss(int idx1, int idx2)
{

    if (idx1 < 0 || idx2 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    long ans = max(lcss(idx1 - 1, idx2), lcss(idx1, idx2 - 1), lcss(idx1 - 1, idx2 - 1) + (s1[idx1] == s2[idx2]) ? 1 : 0);

    return dp[idx1][idx2] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    return 0;
}
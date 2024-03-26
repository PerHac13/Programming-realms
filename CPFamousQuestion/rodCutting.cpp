#include <bits/stdc++.h>
using namespace std;
#define f(i, s, e) for (long long i = s; i < e; ++i)
const int N = 1e5 + 10;
vector<int> dp(1005, -1);

int funct(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int ans = 0;
    for (int len_to_cut = 1; len_to_cut <= prices.size(); ++len_to_cut)
    {
        if (len - len_to_cut >= 0)
        {
            ans = max(ans, funct(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
    }
    return dp[len] = ans;
}

int cutRod(int price[], int n)
{
    vector<int> prices(price, price + n);
    return funct(n, prices);
}
// T.C. =>  O (N^2)
int main()
{

    return 0;
}
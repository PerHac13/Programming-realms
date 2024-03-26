#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int binexp(int a, int b, int m)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}

// Modular Multiplicative Inverse
// Fermet Theorem
int main()
{

    int n;
    cin >> n;

    int Inv = binexp(n, M - 2, M);

    return 0;
}
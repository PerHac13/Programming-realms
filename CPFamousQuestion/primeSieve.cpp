#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> hprime(N, 0), lprime(N, 0);

void sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < N; ++i)
    {
        lprime[i] = hprime[i] = i;
        if (isPrime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                hprime[j] = i;
                isPrime[j] = 0;
                if (!lprime[j])
                    lprime[j] = i;
            }
        }
    }
}

int main()
{

    return 0;
}
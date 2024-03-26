#include <bits/stdc++.h>

using namespace std;

// Catalan Number:
/*
    A sequence of a natural nunmbers that  occur is various counting problems, often involving recursively defined objects.
    Their closed form is in terms of binomial coefficients:
        Cn = 1/(n+1) 2nCn = Summation of  CiCn-i, i=0 to n-1
    C0 : 1 C1 :1 predefine
    C2 : C0C1+C1C0 : 2
    C3 : C0C2 + C1C1 +C2C0 : 5
    C4 : C0C3 + C1C2 +C2C1 +C3C0 :..14
*/

int catalan(int n)
{
    // tC: O(n!)
    if (n < 2)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}
/*
    Applications:
        possible Bsts
        paranthesis/bracket combinations
        posiible forest
        ways of traingulations
        possible paths in matrix
        dividing a circle using N chords
        Dyck words of given lenght & much more
*/

int main()
{

    return 0;
}
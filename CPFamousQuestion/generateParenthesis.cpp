#include <bits/stdc++.h>
// backtracking

using namespace std;
vector<string> valid;

void generate(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back(); // for backtracking
    }
    if (close > 0 && close > open)
    {
        s.push_back(')');
        generate(s, open, close - 1);
        s.pop_back(); // for backtracking
    }
    // we pop because we want previous string , not afer pushed string
}

int main()
{

    int n;
    cin >> n;
    string s = "";
    generate(s, n, n);
    for (auto &it : valid)
    {
        cout << it << endl;
    }
    cout << valid.size() << endl;

    return 0;
}
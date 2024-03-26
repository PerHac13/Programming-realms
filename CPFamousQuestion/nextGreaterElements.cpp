#include <bits/stdc++.h>

using namespace std;

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); ++i)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < v.size(); ++i)
        cout << nge[i] << ' ';
    cout << endl;
    return nge;
}

int main()
{

    vector<int> a = {4, 5, 2, 2, 25, 7, 8};
    // for (int i = 0; i < a.size(); ++i)
    //     cout << a[i] << ' ';
    // cout << endl;
    vector<int> nge = NGE(a);
    for (int i = 0; i < a.size(); ++i)
    {
        int tmp = nge[i];
        cout << tmp << ' ';
        if (tmp == -1)
            cout << -1;
        else
            cout << a[tmp];
        cout << endl;
    }

    return 0;
}
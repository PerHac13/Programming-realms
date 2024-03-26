#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];
multiset<int> sizes;
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
    sizes.insert(1);
}
int find(int v)
{
    if (v == parent[v])
        return v;
    // check forpath compression
    return parent[v] = find(parent[v]);
}
void merge(int a, int b)
{
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));
    sizes.insert(size[a] + size[b]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        merge(a, b);
        size[a] += size[b];
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int connected_ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(i) == i)
            connected_ct++;
    }

    return 0;
}
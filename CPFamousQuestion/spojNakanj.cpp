#include <bits/stdc++.h>

using namespace std;
int vis[8][8], lvl[8][8];

int getX(string s)
{
    return s[0] - 'a';
}
int getY(string s)
{
    return s[1] - '1';
}
vector<pair<int, int>> movements = {
    {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int bfs(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;

    while (!q.empty())
    {
        pair<int, int> cur_v = q.front();
        q.pop();
        int x = cur_v.first, y = cur_v.second;
        for (auto movement : movements)
        {
            int childX = x + movement.first;
            int childY = y + movement.second;
            if (!isValid(childX, childY))
                continue;
            if (!vis[childX][childY])
            {
                q.push({childX, childY});
                lvl[childX][childY] = lvl[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
    }
    return lvl[destX][destY];
}

int main()
{

    string s, d;
    cin >> s >> d;

    return 0;
}
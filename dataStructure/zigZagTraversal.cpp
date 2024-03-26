#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigZagTravesal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> currLvl, nxtLvl;
    bool leftToRight = 1;
    currLvl.push(root);
    while (!currLvl.empty())
    {
        Node *tmp = currLvl.top();
        currLvl.pop();

        if (tmp)
        {
            cout << tmp->data << " ";

            if (leftToRight)
            {
                if (tmp->left)
                    nxtLvl.push(tmp->left);
                else
                    nxtLvl.push(tmp->right);
            }
            else
            {
                if (tmp->right)
                    nxtLvl.push(tmp->right);
                if (tmp->left)
                    nxtLvl.push(tmp->left);
            }
        }
        if (currLvl.empty())
        {
            leftToRight = !leftToRight;
            swap(currLvl, nxtLvl);
        }
    }
}

int main()
{

    return 0;
}
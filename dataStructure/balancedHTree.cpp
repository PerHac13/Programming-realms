#include <bits/stdc++.h>

using namespace std;

// define dataTypes
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

// Basic  Functionality
void preOrder(struct Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int calcHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

bool isBHT(Node *root, int *height)
{
    // TC : O(n)

    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (isBHT(root->left, &lh) == false)
        return false;
    if (isBHT(root->right, &rh) == false)
        return false;

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

bool isBHT(Node *root)
{
    // TC: O(n*n)
    if (root == NULL)
        return true;

    if (isBHT(root->left) == false)
        return false;
    if (isBHT(root->right) == false)
        return false;

    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

void rightViewBHT(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

void leftviewBHT(Node *root)
{

    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

// Questions
// 1
Node *LCA(Node *root, int n1, int n2)
{
    // Least common ancestor

    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return dist;

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
        return left;
    return findDist(root->right, k, dist + 1);
}

int distBW2Node(Node *root, int n1, int n2)
{
    /* Find the dist b/w two nodes in a binary tree. the distance between two nodes is the min no. of edges to traversed to reach one node from another. */

    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    cout << d1 << " " << d2 << endl;

    return d1 + d2;
}

// 2
void flatten(Node *root)
{
    /* Given a binary tree flatten it into linked list in place. after flattening, left of each node should point
    to NULL and right should contain next node in preorder sequence.*/

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
            t = t->right;

        t->right = temp;
    }
    flatten(root->right);
}

// 3
void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}
int printNodesAtk(Node *root, Node *target, int k)
{
    // Nodes at distance K in BT
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << " ";
        else
        {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodesAtk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << " ";
        else
        {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

// 4
bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}
// But above LCA have less TC
int LCAncestor(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return -1;

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
        if (path1[pc] != path2[pc])
            break;
    return path1[pc - 1];
}

// 5
int maxPathSumUntil(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = maxPathSumUntil(root->left, ans);
    int right = maxPathSumUntil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUntil(root, ans);
    return ans;
}

int main()
{
    /*
                    1
                /       \
              2            3
           /    \         /   \
         4       5       6       7
    */

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;
    cout << isBHT(root, &height) << endl;
    rightViewBHT(root);
    cout << endl;
    leftviewBHT(root);
    cout << endl;
    cout << distBW2Node(root, 4, 7) << endl;
    // flatten(root);
    inOrder(root);
    cout << endl;
    printNodesAtk(root, root->left, 3);
    cout << endl;
    cout << maxPathSum(root) << endl;

    return 0;
}
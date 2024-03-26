#include <iostream>
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

// Travansing BT
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

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void printLvlOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

// Basic Functionality

int countNode(Node *root)
{

    // To count number of nodes present in BT

    if (root == NULL)
        return 0;

    return countNode(root->left) + countNode(root->right) + 1;
}

int calcHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(lDiameter, currDiameter, rHeight);
}

int calcDiameter(Node *root, int *height)
{
    // more optimize O(n)

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

// Building tree with PreOrder and InOrder;

int searchPrI(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1; // never come to this
}

Node *buildTreePrI(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = searchPrI(inorder, start, end, curr);
    node->left = buildTreePrI(preorder, inorder, start, pos - 1);
    node->right = buildTreePrI(preorder, inorder, pos + 1, end);
}

// Buiding BT with PostOrder and InOrder

int searchPoI(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1; // never come to this
}

Node *buildTreePoI(int postorder[], int inorder[], int start, int end)
{
    static int idx = end - 1;
    if (start > end)
        return NULL;

    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = searchPoI(inorder, start, end, curr);
    node->left = buildTreePrI(postorder, inorder, pos + 1, end);
    node->right = buildTreePrI(postorder, inorder, start, pos - 1);

    return node;
}

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        if (cond1 && cond2 && cond3)
            return true;
        return false;
    }
}
// Questions

int sumAtKthlvl(Node *root, int k)
{
    /* question states that we need to find the sume of nodes at kth lvl */

    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int lvl = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (lvl == k)
                sum += node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            lvl++;
        }
    }

    return sum;
}

int sumOfNodes(Node *root)
{

    // Sum of all element of BT

    if (root == NULL)
        return 0;

    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

void sumReplace(Node *root)
{
    /* Replace the value of each nodes with the sum of all subtree nodes and itself*/

    if (root == NULL)
        return;

    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}

// Queestion : Largest BST size in BT
struct info
{
    int size, mx, mn, ans;
    bool isBST;
};

info largestBSTinBT(Node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    info leftInfo = largestBSTinBT(root->left);
    info rightInfo = largestBSTinBT(root->right);

    info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.mx < root->data && rightInfo.mn > root->data)
    {
        curr.mn = min(leftInfo.mn, min(rightInfo.mn, root->data));
        curr.mx = max(rightInfo.mx, max(leftInfo.mx, root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // int height=0;
    // calcDiameter(root,&height);
}

// PreOrder
// 1,2,4,5,3,6,7

// InOrder
// 4,2,5,1,6,3,7

// PostOrder
// 4,5,2,6,7,3,1

// LevelOrder
// 1,2,3,4,5,6,7

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

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

Node *searchBST(Node *root, int key)
{ // TC: O(logN)

    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;
    if (root->data < key)
        return searchBST(root->right, key);
    else
        return searchBST(root->left, key);
}

Node *inOrderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
        root->left = deleteInBST(root->left, key);
    else if (key > root->data)
        root->right = deleteInBST(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        // two child case
        Node *tmp = inOrderSucc(root->right);
        root->data = tmp->data;
        root->right = deleteInBST(root->right, key);
    }
    return root;
}

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    // TC: O(n)
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
}

bool isBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    // TC: O(N)
    if (root == NULL)
        return true;

    if (min != NULL && root->data <= min->data)
        return false;
    if (max != NULL && root->data >= max->data)
        return false;

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid && rightValid;
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

// Ques: Restore BST if two node get swapped

void calcPointer(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
        return;
    calcPointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, first, mid, last, prev);
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = *a;
}

void restoreBST(Node *root)
{
    Node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
    calcPointer(root, &first, &mid, &last, &prev);
    if (first && last)
        swap(&(first->data), &(last->data));
    else if (first && mid)
        swap(&(first->data), &(mid->data));
}

int main()
{
    Node *root = NULL;
    insertBST(root, 3);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 8);
    insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 6);
    insertBST(root, 4);

    inOrder(root);
    cout << endl;

    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node *root1 = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    preOrder(root1);
    cout << endl;
    cout << isBST(root1, NULL, NULL) << endl;

    return 0;
}
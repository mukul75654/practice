#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void f(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    f(root->left, inorder);
    inorder.push_back(root->data);
    f(root->right, inorder);
}
Node *helper(vector<int>& inorder, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = newNode(inorder[mid]);
    root->left = helper(inorder, start, mid - 1);
    root->right = helper(inorder, mid + 1, end);
    return root;
}

Node *buildBalancedTree(Node *root)
{
    vector<int> inorder;
    f(root, inorder);
    int n = inorder.size();
    return helper(inorder, 0, n - 1);
}

void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}

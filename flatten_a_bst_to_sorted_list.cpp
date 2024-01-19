#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    TreeNode<int> *newRoot = new TreeNode<int>(in[0]);
    TreeNode<int> *curr = newRoot;
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(in[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
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

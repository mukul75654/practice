#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

set<int> st;


void f(Node *root)
{
    if (root == NULL)
        return;
    f(root->left);
    st.insert(root->data);
    f(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    root->data = *st.begin();
    st.erase(st.begin());

    inorder(root->right);
}
Node *binaryTreeToBST(Node *root)
{
    f(root);
    inorder(root);
    return root;
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

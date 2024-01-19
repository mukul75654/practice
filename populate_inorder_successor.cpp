#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
Node *pre = NULL;
void populateNext(Node *root)
{
    if (root == NULL)
        return;
    populateNext(root->right);
    root->next = pre;
    pre = root;
    populateNext(root->left);
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

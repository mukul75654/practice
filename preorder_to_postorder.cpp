#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node *f(int pre[], int &ind, int n, int b)
{
    if (ind >= n || pre[ind] >= b)
        return NULL;
    Node *root = newNode(pre[ind++]);
    root->left = f(pre, ind, n, root->data);
    root->right = f(pre, ind, n, b);
    return root;
}
Node *post_order(int pre[], int size)
{
    int ind = 0;
    return f(pre, ind, size, INT_MAX);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool f(TreeNode *root, long long minVal, long long maxVal)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return f(root->left, minVal, root->val) && f(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode *root)
    {
        long long int_min = -1e11;
        long long int_max = 1e11;

        return f(root, int_min, int_max);
    }
};
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

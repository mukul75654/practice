#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Interval
{
    int low, high;
};
struct ITNode
{
    Interval *it;
    int max;
    ITNode *left, *right;
};
ITNode *newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->it = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
}

ITNode *insert(ITNode *root, Interval i)
{
    if (root == NULL)
    {
        return newNode(i);
    }
    int l = root->it->low;
    if (i.low < l)
    {
        root->left = insert(root->left, i);
    }
    else
    {
        root->right = insert(root->right, i);
    }
    if (root->max < i.high)
    {
        root->max = i.high;
    }

    return root;
}

bool doOverlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i1.high > i2.low)
        return true;
    return false;
}
Interval *overlapSearch(ITNode *root, Interval i)
{
    if (root == NULL)
        return NULL;
    if (doOverlap(*(root->it), i))
        return root->it;

    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
    return overlapSearch(root->right, i);
}
void printConflicting(Interval appt[], int n)
{
    ITNode *root = NULL;
    root = insert(root, appt[0]);
    for (int i = 1; i < n; i++)
    {
        Interval *res = overlapSearch(root, appt[i]);
        if (res != NULL)
        {
            cout << "[" << appt[i].low << "," << appt[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
        }
        root=insert(root,appt[i]);
    }
}

void solve()
{
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
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

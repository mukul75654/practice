#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f(int i, int j, int keys[], int freq[], int n, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return freq[i];

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int res = f(i, k - 1, keys, freq, n, dp) + f(k + 1, j, keys, freq, n, dp);
        ans = min(ans, res);
    }
    for (int l = i; l <= j; l++)
        ans += freq[l];
    return dp[i][j] = ans;
}
int optimalSearchTree(int keys[], int freq[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return f(0, n - 1, keys, freq, n, dp);
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

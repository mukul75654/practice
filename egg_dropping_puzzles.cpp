#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int n, int k, vector<vector<int>> &dp)
{

    if (k == 0 || k == 1)
        return k;
    if (n == 1)
        return k;
    if (dp[n][k] != -1)
        return dp[n][k];
    int ans = INT_MAX;

    for (int x = 1; x <= k; x++)
    {
        int res = max(f(n - 1, x - 1, dp), f(n, k - x, dp));
        ans = min(ans, res);
    }

    return dp[n][k] = ans+1;
}

int superEggDrop(int k, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return f(n, k, dp);
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

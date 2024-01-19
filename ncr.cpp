#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int nCr(int n, int r, vector<vector<int>> &dp)
{
    if (r == 0 || r == n)
        return 1;
    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp);
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

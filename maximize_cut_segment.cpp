#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
    int f(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if(dp[n]!=-1)return dp[n];
    int a = 1 + f(n - x, x, y, z, dp);
    int b = 1 + f(n - y, x, y, z, dp);
    int c = 1 + f(n - z, x, y, z, dp);
    return dp[n] = max(a, (max(b, c)));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans=f(n, x, y, z, dp);
    return ans>=0 ? ans :0;
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

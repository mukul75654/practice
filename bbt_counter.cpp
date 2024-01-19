#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long long int f(int h, vector<long long int> &dp)
{
    if (h == 0 || h == 1)
        return 1;
    if (dp[h] != -1)
        return dp[h];
    return dp[h] = (f(h - 1, dp) % mod) * ((2 * f(h - 2, dp)) % mod + (f(h - 1, dp) % mod)) % mod;
}
long long int countBT(int h)
{
    vector<long long int> dp(h + 1, -1);
    return f(h, dp);
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

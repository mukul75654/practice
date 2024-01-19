#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long int disarrange(int N, vector<long long int> &dp)
{
    if (N == 1)
    {
        return 0;
    }
    if (N == 2)
        return 1;
    if (dp[N] != -1)
        return dp[N];
    return dp[N] = ((N - 1) * 1LL * (disarrange(N - 1, dp) % mod + disarrange(N - 2, dp) % mod)) % mod;
}
long int disarrange(int N)
{
    // code here
    vector<long long int> dp(N + 1, -1);
    return disarrange(N, dp) % mod;
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

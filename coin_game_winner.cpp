#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int findWinner(int N, int X, int Y)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (i >= 1 && !dp[i - 1])
            dp[i] = 1;
        else if (i >= X && !dp[i - X])
            dp[i] = 1;
        else if (i >= Y && !dp[i - Y])
            dp[i] = 1;

        else
            dp[i] = 0;
    }
    return dp[N];
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

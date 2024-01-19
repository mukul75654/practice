#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int n, int m, string s1, string s2, vector<vector<int>> &dp)
{

int ans=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans=max(ans,dp[i][j]);
            }

            else
                dp[i][j] = 0;
        }
    }
     return ans;
}

int longestCommonSubstr(string A, string B, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return f(n, m, A, B, dp);
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

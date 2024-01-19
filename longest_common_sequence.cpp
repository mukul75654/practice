#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    int n=text1.length();
    int m=text2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return f(n-1,m-1,text1,text2,dp);

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

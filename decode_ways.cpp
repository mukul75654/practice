#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, string &s, vector<int> &dp)
{
    if (i == 0 || i == 1)
        return 1;
    if (s[0] == '0')
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int count = 0;
    if (s[i - 1] > '0')
        count += f(i - 1, s, dp);
    if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
    {
        count += f(i - 2, s, dp);
    }
    return dp[i] = count;
}

int numDecodings(string s)
{

    int n = s.length();
    if (n == 0 || n == 1 && s[0] == '0')
        return 0;
    vector<int> dp(n + 1, -1);
    return f(n, s, dp);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int j, vector<vector<int>> &M, vector<vector<int>> &dp)
{
    int n = M.size();
    int m = M[0].size();

    if (i < 0 || j >= m || i >= n)
    {
        return (-1e9);
    }

    if (j == m - 1)
    {
        return M[i][m - 1];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int r = M[i][j] + f(i, j + 1, M, dp);
    int ru = M[i][j] + f(i - 1, j + 1, M, dp);
    int rd = M[i][j] + f(i + 1, j + 1, M, dp);
    return dp[i][j] = max(r, max(ru, rd));
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, f(i, 0, M, dp));
    }
    return ans;
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

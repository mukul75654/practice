#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp, int &maxi)
{

    if (i == mat.size() || j == mat[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int bottom = f(i + 1, j, mat, dp, maxi);
    int right = f(i, j + 1, mat, dp, maxi);
    int diagonal = f(i + 1, j + 1, mat, dp, maxi);

    if (mat[i][j] == 1)
    {

        int ans = 1 + min(diagonal, min(bottom, right));
        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }

    else
    {

        return dp[i][j] = 0;
    }
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    f(0, 0, mat, dp, maxi);
    return maxi;
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

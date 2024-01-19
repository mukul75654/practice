#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int j, vector<vector<int>> &Matrix, vector<vector<int>> &dp)
{
    int n = Matrix.size();
    int m = Matrix[0].size();
    if (j < 0 || j >= m)
    {
        return INT_MIN;
    }
    if (i == 0)
    {
        return Matrix[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int ld = f(i - 1, j - 1, Matrix, dp);
    int st = f(i - 1, j, Matrix, dp);
    int rd = f(i - 1, j + 1, Matrix, dp);
    return dp[i][j] = Matrix[i][j] + max(st, max(ld, rd));
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
   vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    int ans=INT_MIN;
    for(int i=0;i<N;i++){
        ans=max(ans,f(N-1,N-1-i,Matrix,dp));
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

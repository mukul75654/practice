#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f(int i, int j, int N, int arr[], vector<vector<int>> &dp)
{

    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int step = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int min_step = arr[i - 1] * arr[k] * arr[j] + f(i, k, N, arr, dp) + f(k + 1, j, N, arr, dp);
        step = min(step, min_step);
    }
    return dp[i][j] = step;
}

int matrixMultiplication(int N, int arr[])
{
    // vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
    // return f(1,N-1,N,arr,dp);
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int step = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int min_step = arr[i - 1] * arr[k] * arr[j] + f(i, k, N, arr, dp) + f(k + 1, j, N, arr, dp);
                step = min(step, min_step);
            }
            dp[i][j] = step;
        }
    }
    return dp[1][N - 1];
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

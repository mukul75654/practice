#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int index, int p, vector<int> &coins, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (p % coins[index] == 0)
        {
            return p / coins[index];
        }
        else
        {
            return (1e9);
        }
    }
    if (dp[index][p] != -1)
        return dp[index][p];
    int not_pick = f(index - 1, p, coins, dp);
    int pick = INT_MAX;
    if (coins[index] <= p)
    {
        pick = 1 + f(index, p - coins[index], coins, dp);
    }
    return dp[index][p]= min(pick, not_pick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    int ans= f(n-1,amount,coins,dp);
    return ans>=1e9 ? -1 : ans;
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

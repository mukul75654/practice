#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool f(int ind, vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();

    if (ind == n - 1)
        return true;
    if (nums[ind] == 0)
        return false;
    if (dp[ind] != -1)
        return dp[ind];
    bool temp = false;
    int reach = ind + nums[ind];

    for (int i = ind + 1; i <= reach; i++)
    {
        if (i < n && f(i, nums, dp))
            return dp[ind] = true;
    }
    return dp[ind] = false;
}
bool canJump(vector<int> &nums)
{
    // int n=nums.size();
    // vector<int>dp(n+1,-1);
    // return f(0,nums,dp);

    // int n = nums.size();
    // vector<int> dp(n + 1, 0);
    // dp[n - 1] = 1;

    // for (int ind = n - 2; ind >= 0; ind--)
    // {
    //     if (nums[ind] == 0)
    //     {
    //         dp[ind] = false;
    //         continue;
    //     }
    //     int reach = ind + nums[ind];
    //     int flag = 0;
    //     for (int i = ind + 1; i <= reach; i++)
    //     {
    //         if (i < n && dp[i])
    //         {
    //             dp[ind] = true;
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //         dp[ind] = false;
    // }
    // return dp[0];

    
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

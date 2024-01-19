#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f(int ind, int prev, int pos, vector<int> &nums, int n, vector<vector<vector<int>>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][prev + 1][pos] != -1)
        return dp[ind][prev + 1][pos];
    if (pos)
    {
        int pick = 0;
        int not_pick = 0;
        if (prev == -1 || nums[ind] - prev > 0)
        {
            pick = 1 + f(ind + 1, nums[ind], 0, nums, n, dp);
        }
        not_pick = f(ind + 1, prev, 1, nums, n, dp);
        return dp[ind][prev + 1][pos] = max(pick, not_pick);
    }
    else
    {
        int pick = 0;
        int not_pick = 0;
        if (prev == -1 || nums[ind] - prev < 0)
        {
            pick = 1 + f(ind + 1, nums[ind], 1, nums, n, dp);
        }
        not_pick = f(ind + 1, prev, 0, nums, n, dp);
        return dp[ind][prev + 1][pos] = max(pick, not_pick);
    }
}
int wiggleMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(1005, vector<int>(2, -1)));

    int ans1 = f(0, -1, 0, nums, n, dp);
    int ans2 = f(0, -1, 1, nums, n, dp);
    return max(ans1, ans2);
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

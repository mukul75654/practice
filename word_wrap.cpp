#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int rem, int k, int n, vector<int> &nums, vector<vector<int>> &dp)
{

    if (i == n - 1)
    {
        if (nums[i] < rem)
        {
            return dp[i][rem] = 0;
        }
        else
        {
            return dp[i][rem] = (rem) * (rem);
        }
    }
    if (dp[i][rem] != -1)
        return dp[i][rem];

    int word_length = nums[i];

    if (word_length < rem)
    {
        int pick = INT_MAX;
        pick = f(i + 1, rem == k ? rem - word_length : rem - word_length - 1, k, n, nums, dp);

        int not_pick = rem * rem + f(i + 1, k - word_length, k, n, nums, dp);

        return dp[i][rem] = min(pick, not_pick);
    }
    return dp[i][rem] = rem * rem + f(i + 1, k - word_length, k, n, nums, dp);
}

int solveWordWrap(vector<int> nums, int k)
{
    // Code here
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(0, k, k, n, nums, dp);
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

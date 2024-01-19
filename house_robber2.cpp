#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (ind == 0)
        return nums[0];
    if (dp[ind] != -1)
        return dp[ind];
    int not_pick = f(ind - 1, nums, dp);
    int pick = INT_MIN;

    pick = f(ind - 2, nums, dp) + nums[ind];
    return dp[ind] = max(not_pick, pick);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if(n==1)return nums[0];
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    return max(f(n - 2, temp1, dp1), f(n - 2, temp2, dp2));
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

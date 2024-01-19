#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
  int f(int index, int prev,int n, int nums[],vector<vector<int>>&dp)
{
     if(index ==n){
        return 0;
    }
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];

    int not_take = 0 + f(index + 1, prev,n, nums,dp);
    int take = INT_MIN;
    if (prev == -1 || abs(nums[index] - nums[prev])==1)
    {
        take = 1 + f(index + 1, index,n, nums,dp);
    }
    return dp[index][prev+1]=max(take, not_take);
}
    int longestSubsequence(int n, int nums[])
    {
    
        //   int n=nums.size();
         // int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(0,-1,n,nums,dp);
  
    }
void solve()
{
    
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}

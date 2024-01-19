#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int target,vector<int>& nums,vector<int>&dp){
  if(target==0){
    return 1;
  }
  if(target<0){
    return 0;
  }
  if(dp[target]!=-1)return dp[target];
  int ways=0;
  for(auto it:nums){
    ways+=f(target-it,nums,dp);
  }
  return dp[target]= ways;
}

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
            vector<int>dp(target+1,-1);
            return f(target,nums,dp);
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

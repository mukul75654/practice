#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
   int f(int i,int n,vector<int>& arr,vector<int>&dp){
    if(i>=n ){
        return (1e9);
    }
    if(i==n-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int min_cost=1e9;
    for (int j = i+1; j < min(n, i+arr[i]+1 ); j++)
    {
        
        int ans = 1 + f(j , n, arr, dp);
        min_cost = min(ans, min_cost);
    }
    return dp[i] = min_cost;
}
    int jump(vector<int>& nums) {
         int n=nums.size();
        vector<int>dp(n,-1);
       
        int ans= f(0,n,nums,dp);
        return ans>=1e9 ? -1:ans;
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

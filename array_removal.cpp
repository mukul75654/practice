#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
  int f(int i,int j,int k,vector<int>&arr,vector<vector<int>>&dp){
        
        if(i==j)return 0;
        
        if(arr[j]-arr[i]<=k){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min(f(i+1,j,k,arr,dp),f(i,j-1,k,arr,dp));
        
        
    }
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,k,arr,dp);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
    long long int f(int i,int j,int arr[],int n,vector<vector<long long int>>&dp){
        if(i==j)return arr[i];
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int l=arr[i]+min(f(i+2,j,arr,n,dp),f(i+1,j-1,arr,n,dp));
        long long int r=arr[j]+min(f(i,j-2,arr,n,dp),f(i+1,j-1,arr,n,dp));
        return dp[i][j]=max(l,r);
    }
    long long maximumAmount(int arr[], int n){
        
        vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
        return f(0,n-1,arr,n,dp);
        
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

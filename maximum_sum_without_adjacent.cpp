#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i,vector<int>&arr,vector<int>&dp){
    if(i<0){
        return 0;
    }
    if(i==0){
        return arr[0];
    }
    if(dp[i]!=-1)return dp[i];

    int a=f(i-1,arr,dp);
    int b=arr[i]+arr[i-1]+f(i-3,arr,dp);
    int c=arr[i]+f(i-2,arr,dp);
    return dp[i]=max(a,max(b,c));
}
int findMaxSum(vector<int>& a){
     vector<int>dp(a.size(),-1);
     if(a.size()<3){
        return accumulate(a.begin(),a.end(),0);
     }
     return f(a.size()-1,a,dp);
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

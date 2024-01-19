#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int ind ,int trans,vector<int>&arr,vector<vector<int>>&dp){
    if(trans==4||ind==arr.size())return 0;
    if(dp[ind][trans]!=-1)return dp[ind][trans];
    int profit=0;
    if(trans%2==0){
        profit=max(-arr[ind]+f(ind+1,trans+1,arr,dp),f(ind+1,trans,arr,dp));
    }else{
        profit=max(arr[ind]+f(ind+1,trans+1,arr,dp),f(ind+1,trans,arr,dp));
    }
    return dp[ind][trans]=profit;
}
int maxProfit(vector<int>&arr){
    //Write your code here..
    int n=arr.size();
    
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(0,0,arr,dp);
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

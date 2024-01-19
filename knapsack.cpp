#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 int f(int index,int val[],int wt[],int maxwt,vector<vector<int>>&dp){
         if(maxwt==0)return 0;
         
         if(index==0){
             if(maxwt>=wt[index]){
                 return val[0];
                 }
             else return 0;
         }
         
         if(dp[index][maxwt]!=-1)return dp[index][maxwt];
         int not_pick=f(index-1,val,wt,maxwt,dp);
         int pick=INT_MIN;
         if(wt[index]<=maxwt){
             pick=val[index]+f(index-1,val,wt,maxwt-wt[index],dp);
         }
         return dp[index][maxwt]=max(not_pick,pick);
     }
 

 int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,val,wt,W,dp);
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

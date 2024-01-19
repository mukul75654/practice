#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 int f(int ind,int prev,vector<vector<int>>& pairs,vector<vector<int>>&dp){
    int n=pairs.size();
    if(ind == n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
    int not_pick=f(ind+1,prev,pairs,dp);
    int pick=0;
    if(prev==-1 || pairs[ind][0]>pairs[prev][1]){
        pick=1+f(ind+1,ind,pairs,dp);
    }
    return dp[ind][prev+1]= max(pick,not_pick);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,pairs,dp);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i,int j,int m,int n,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int left=f(i,j-1,m,n,dp);
    int up=f(i-1,j,m,n,dp);
    return dp[i][j]=left+up;
}

 int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return f(i-1,j-1,s1,s2,dp);
        }
        int insert=1+f(i,j-1,s1,s2,dp);
        int Delete=1+f(i-1,j,s1,s2,dp);
        int replace=1+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=min(insert,min(Delete,replace));
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
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

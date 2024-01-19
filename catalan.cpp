#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

unsigned long long int  catalan(int n,vector<unsigned long long>&dp){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1)return dp[n];
   unsigned long long res=0;
    for(int i=0;i<n;i++){
    res+=catalan(i,dp)*catalan(n-i-1,dp);
    }
    return dp[n]= res;
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


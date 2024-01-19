#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long int f(long long int ind,long long int k,vector<vector<long long int>>&dp,vector<int>&arr){
       if(k==0){
           return 1;
       }
       if(ind==0){
           return k%arr[ind]==0;
       }
       if(dp[ind][k]!=-1)return dp[ind][k];
       long long not_pick=f(ind-1,k,dp,arr);
       long long pick=0;
       if(k>=arr[ind]){
           pick=f(ind,k-arr[ind],dp,arr);
       }
       return dp[ind][k]=pick+not_pick;
       
}

long long int count(long long int n)
{
	vector<int>arr={3,5,10};
	vector<vector<long long int>>dp(3,vector<long long int>(n+1,-1));
	return f(2,n,dp,arr);

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

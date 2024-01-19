#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f(int index,int prev,int n,int arr[],vector<vector<int>>&dp){
    if(index == n){
        return 0;
    }
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];
    int not_pick=f(index+1,prev,n,arr,dp);
    int pick=0;
    if(prev==-1 || arr[index]>arr[prev]){
     pick=arr[index]+f(index+1,index,n,arr,dp);
    }
    return dp[index][prev+1]=max(pick,not_pick);

}

	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,arr,dp);
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

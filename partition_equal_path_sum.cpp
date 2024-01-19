#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f(int index, int target, int N, int arr[],vector<vector<int>>&dp)
{
    if (index == 0)
    {
        return target == arr[index];
    }
    if(dp[index][target]!=-1)return dp[index][target];
    int pick = 0;
    if (target >= arr[index])
    {
        pick = f(index - 1, target - arr[index], N, arr,dp);
    }
    int not_pick = f(index - 1, target, N, arr,dp);
    return dp[index][target]= pick | not_pick;
}
int equalPartition(int N, int arr[])
    {
       int sum=0;
       sum=accumulate(arr,arr+N,0);
       if(sum%2==1)return false;
       vector<vector<int>>dp(N,vector<int>(sum+1,-1));
       return f(N-1,sum/2,N,arr,dp);

    }

void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}

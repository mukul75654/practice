#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct job
{
    int start;
    int end;
    int profit;
};

static bool cmp(job s1, job s2)
{
    return s1.end < s2.end;
}

int latestNonConflicting(job arr[],int i){
    for(int j=i-1 ;j>=0;j--){
        if(arr[j].end<=arr[i].start){
            return j;
        }
    }
    return -1;
}
int maxProfit(job arr[],int n,vector<int>&dp){
    if(n==0){
        return arr[n].profit;
    }
    if(dp[n]!=-1)return dp[n];
    int pick=arr[n].profit;
    int i=latestNonConflicting(arr,n);
    if(i!=-1){
        pick+=maxProfit(arr,i,dp);
    }
    int not_pick=maxProfit(arr,n-1,dp);
    return dp[n]= max(pick,not_pick);
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    struct job arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].start = startTime[i];
        arr[i].end = endTime[i];
        arr[i].profit = profit[i];
    }
    sort(arr,arr+n,cmp);
    vector<int>dp(n,-1);
    return maxProfit(arr,n-1,dp);
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

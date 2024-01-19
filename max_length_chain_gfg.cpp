#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct val
{
    int first;
    int second;
};
static bool cmp(struct val p1, struct val p2)
{
    return p1.second < p2.second;
}

int f(int index, int prev, struct val nums[], vector<vector<int>> &dp, int n)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    int not_take = 0 + f(index + 1, prev, nums, dp, n);
    int take = INT_MIN;
    if (prev == -1 || nums[index].first > nums[prev].second)
    {
        take = 1 + f(index + 1, index, nums, dp, n);
    }
    return dp[index][prev + 1] = max(take, not_take);
}
/*You are required to complete this method*/
int maxChainLen(struct val nums[], int n)
{

    sort(nums, nums + n, cmp);

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp, n);
}
  bool static comp(val fst,val sec){
        return fst.second<sec.second;
    }
    
    int maxChainLen(struct val p[],int n){
        sort(p,p+n,comp);
        int ans=0;
        int prev=-1e9;
        for(int i=0;i<n;i++){
            if(p[i].first>prev){
                prev=p[i].second;
                ans++;
            }
        }
        return ans;
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


//time complexity O(2^N)
//space complexity O(n)


//time complexity O(N^N)
//space complexity O(n)+O(N^N)

int f(int index, int prev, vector<int> &nums,vector<vector<int>>&dp)
{
     if(index ==nums.size()){
        return 0;
    }
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];

    int not_take = 0 + f(index + 1, prev, nums,dp);
    int take = INT_MIN;
    if (prev == -1 || nums[index] > nums[prev])
    {
        take = 1 + f(index + 1, index, nums,dp);
    }
    return dp[index][prev+1]=max(take, not_take);
}

int lengthOfLIS(vector<int> &nums)
{
    // int n=nums.size();
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return f(0,-1,nums,dp);

    // int n=nums.size();
    // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // // return f(0,-1,nums,dp);
    // for(int index=n-1;index>=0;index--){
    //     for(int prev=index-1;prev>=-1;prev--){
    //             int not_take = 0 + dp[index+1][prev+1];
    // int take = INT_MIN;
    // if (prev == -1 || nums[index] > nums[prev])
    // {
    //     take = 1 + dp[index+1][index+1];
    // }
    //  dp[index][prev+1]=max(take, not_take);
    //     }
    // }
    // return dp[0][0];

        int n=nums.size();
    // vector<int>after(n+1,0),curr(n+1,0);
    // // return f(0,-1,nums,dp);
    // for(int index=n-1;index>=0;index--){
    //     for(int prev=index-1;prev>=-1;prev--){
    //             int not_take = 0 + after[prev+1];
    // int take = INT_MIN;
    // if (prev == -1 || nums[index] > nums[prev])
    // {
    //     take = 1 + after[index+1];
    // }
    //  curr[prev+1]=max(take, not_take);
    //     }
    //     after=curr;
    // }
    // return after[0];


    int n=nums.size();
    vector<int>dp(n,1);
    vector<int>hash(n,0);
    int maxi=INT_MIN;
    int lastIndex=0;
    for(int i=0;i<n;i++)hash[i]=i;

    for(int index=0;index<n;index++){
        for(int prev=0;prev<=index-1;prev++){
            if(nums[index]>nums[prev] && 1+dp[prev]>dp[index]){
              dp[index]=1+dp[prev];
              hash[index]=prev;
            }
        }
        if(dp[index]>maxi){
            maxi=dp[index];
            lastIndex=index;
        }
    }
    int lis[maxi];
    lis[0]=nums[lastIndex];
    int ind=1;
    while(hash[lastIndex]!=lastIndex){
      lastIndex=hash[lastIndex];
      lis[ind++]=nums[lastIndex];

    }
    reverse(lis,lis+maxi);
    return *(max_element(dp.begin(),dp.end()));
}





int     LengthOfLIS(vector<int> &nums)
{
    int n=nums.size();
  vector<int>temp;
  temp.push_back(nums[0]);
  for(int i=0;i<n;i++){
    if(nums[i]>temp[temp.size()-1]){
        temp.push_back(nums[i]);
    }else{
       auto low1 = lower_bound(temp.begin(), temp.end(), nums[i]); 
       auto index=(low1 - temp.begin());
       temp[index]=nums[i];
    }
  }
  return temp.size();

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

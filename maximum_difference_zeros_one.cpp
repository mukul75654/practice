#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int maxSubstring(string S)
	{
        int n=S.length();
	      long long sum=0;
        long long max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            if(S[i]=='0'){
                sum+=1;
            }else{
                sum+=-1;
            }
           
            max_sum=max(max_sum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return max_sum; 
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

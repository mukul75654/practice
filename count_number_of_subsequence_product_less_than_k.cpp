#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f(int i, int p, int pr, vector<int> &nums)
{

    int n = nums.size();

    if (i >= n && p >= 0 && p <= pr)
        return 1;

    if (i >= nums.size())
    {
        return 0;
    }

    int not_pick = f(i + 1, p, pr, nums);
    int pick = 0;
    if (p == -1)
    {
        pick += f(i + 1, nums[i], pr, nums);
    }
    else
    {
        pick += f(i + 1, nums[i] * p, pr, nums);
    }

    return (pick + not_pick) % mod;
}
int countSubsequences(vector<int> &a, int n, int p)
{

    return f(0, -1, p, a) % mod;
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

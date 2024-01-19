#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll f(int n, vector<vector<char>> &keypad, int i, int j, vector<vector<vector<ll>>>&dp)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
        if(dp[i][j][n]!=-1)return dp[i][j][n];
    int delr[] = {0, -1, 0, 1, 0};
    int delc[] = {0, 0, 1, 0, -1};
    ll count = 0;
    for (int m = 0; m < 5; m++)
    {
        int ro = i + delr[m];
        int co = j + delc[m];
        if (ro >= 0 && ro <= 3 && co >= 0 && co < 3 && keypad[ro][co] != '*' && keypad[ro][co] != '#')
        {
            count += f(n - 1, keypad, ro, co,dp);
        }
    }
    return dp[i][j][n]= count;
}
long long getCount(int N)
{
    vector<vector<char>> keypad = {{'1', '2', '3'},
                                   {'4', '5', '6'},
                                   {'7', '8', '9'},
                                   {'*', '0', '#'}};
    if (N == 1)
        return 10;

    ll ans = 0;
    vector<vector<vector<ll>>>dp(4,vector<vector<ll>>(3,vector<ll>(N+1,-1)));

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
            {
                ans += f(N, keypad, i, j,dp);
            }
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

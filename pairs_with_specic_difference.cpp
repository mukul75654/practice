#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Your code goes here
    int sum = 0;
    sort(arr, arr + N);
    int i = N - 1;
    while (i > 0)
    {
        if (arr[i] - arr[i - 1] < K)
        {
            sum += (arr[i - 1] + arr[i]);
            i -= 2;
        }
        else
        {
            i--;
        }
    }
    return sum;
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

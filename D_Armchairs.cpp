#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000000000000
typedef long long ll;
int main()
{
    vector<ll> arr1,arr2;
    ll n;cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll  num ;cin>>num;
        if(num) arr1.push_back(i);
        else arr2.push_back(i);
    }
    ll n1 = arr1.size(); // 1 indexes
    ll n2 = arr2.size(); // 0 indexes
    
    if(n1==0 || n2==0){cout<<0; return 0;}
    vector<vector<ll>> dp(n1+1,vector<ll>(n2+1,INF));
    for(int i=0;i<=n2;i++)dp[0][i] = 0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(arr1[i-1]-arr2[j-1]));
        }
    }
    cout<<dp[n1][n2];
    return 0;
}
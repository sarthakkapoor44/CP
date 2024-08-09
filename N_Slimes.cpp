#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    vector<ll> prefix(n+1);
    prefix[0]=0;
    for(int i=0;i<n;i++)
    {   
        cin>>arr[i];
        prefix[i+1]= arr[i]+prefix[i];
    }
    
    vector<vector<ll> > dp(n,vector<ll> (n,INF));
    for(int i=0;i<n;i++)dp[i][i]=arr[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            for(int k=j;k<=j+i-1;k++)
            {
               if(j+i<n) dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+prefix[j+i+1]-prefix[j] );
            }
        }
    }
    cout<<dp[0][n-1]-prefix[n];
}


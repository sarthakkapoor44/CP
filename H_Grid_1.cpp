#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MODN= 1e9+7;
int main ()
{
    ll n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    vector<vector<ll> > dp(n,vector<ll>(m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#')continue;
            if(i-1>=0)  (dp[i][j] += dp[i-1][j]%MODN)%=MODN;
            if(j-1>=0) (dp[i][j] += dp[i][j-1]%MODN)%=MODN;
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}
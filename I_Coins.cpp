#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<long double> prob(n);
    for(int i=0;i<n;i++){cin>>prob[i];}
    vector<vector<long double> >dp(n,vector<long double>(n+1,0));
    dp[0][0]  = 1-prob[0];
    dp[0][1]  = prob[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i-1>=0) dp[i][j] = dp[i-1][j]*(1-prob[i]);
            if(i-1>=0 && j-1>=0)
            {
                dp[i][j] += prob[i]*dp[i-1][j-1];
            }
        }
    }
    long double ans =0;
    for(int i=(n+1)/2;i<=n;i++){ans+=dp[n-1][i];}
    cout<<setprecision(15)<<ans;
}
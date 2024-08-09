#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll m,n;
    cin>>m>>n;
    vector<ll> arr(m);
    for(int i=0;i<m;i++)cin>>arr[i];
    vector<vector<ll> > dp(1<<m,vector<ll>(n+1,0));
    dp[1<<m-1][0]=1;
    ll ans = 0;
    for(int s= 1;s<(1<<m);s++)
    {
        for(int i=0;i<n;i++)
        {
            for(int b=0;b<m;b++)
            {
                if((s&(1<<b)))
                {
                    ll next=s;
                    if(arr[b]!=b+1)
                    {
                        next=s^(1<<b);
                        for(int j=0;j<m;j++)
                        {
                            if(arr[j]==i+1)
                            {
                                next|=1<<j;
                            }
                        }
                    }
                    dp[next][i+1]+=dp[s][i];
                    if(i+1==n)ans+=dp[next][i+1];
                }
            }
        }
    }
    cout<<ans;

}
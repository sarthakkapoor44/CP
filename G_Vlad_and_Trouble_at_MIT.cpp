#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;cin>>t;
    while(t--)
    {    
        ll n;cin>>n;
        vector<vector<ll>> adj(n);
        for(int i=1;i<n;i++)
        {
            ll a;cin>>a;
            adj[a-1].push_back(i);
            adj[i].push_back(a-1);
        }
        string s;cin>>s;
        vector<ll> dp(n,0);
        for(int i=0;i<n;i++)if(s[i]=='P')dp[i]=1;
        vector<int> vis(n,0);
        function<void(ll)> dfs = [&](ll pos)->void{
            vis[pos]=1;
            for(auto x: adj[pos]){
                if(!vis[x] && s[x]!='S')
                {
                    dfs(x);
                    dp[pos] +=  (dp[x]>0);
                    dp[x]+=1;
                }
            }
        };
        for(int i=0;i<n;i++)if(!vis[i] && s[i]=='P')dfs(i);
        for(auto x: dp)cout<<x<<" ";
        cout<<endl;
    }
}
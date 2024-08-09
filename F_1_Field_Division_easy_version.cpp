#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll> >  fountain(k,vector<ll>(3));
        for(int i=0;i<k;i++)
        {
            ll a,b;cin>>a>>b;
            fountain[i][0]=a;
            fountain[i][1]=-b;
            fountain[i][2]=i;
        }
        sort(fountain.begin(),fountain.end());
        vector<ll> prefix(k+1),suffix(k+1);
        suffix[k]=m;
        prefix[0]=m;
        for(int i=0;i<k;i++)fountain[i][1]*=-1;
        for(int i=1;i<k+1;i++)
        {
            prefix[i]=min(prefix[i-1],fountain[i-1][1]-1);
        }
        for(int i=k-1;i>=0;i--)
        {
            suffix[i] = min(suffix[i+1],fountain[i][1]-1);
        }
        ll area =0;
        ll row=0;
        ll col=m;
        for(int i=0;i<k;i++)
        {
            area += (suffix[i])*(fountain[i][0]-row);
            row=fountain[i][0];
        }
        if(fountain[k-1][0]!=n){area+=m*(n-fountain[k-1][0]);}
        cout<<area<<endl;
        vector<ll> ans(k,0);
        for(int i=0;i<k;i++)
        {
            // cout<<fountain[i][0]<<" "<<fountain[i][1]<<" "<<suffix[i+1]<<endl;
            if(fountain[i][1]-1<suffix[i+1]){ans[fountain[i][2]]=1;}
        }
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
        
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n,m; 
        cin>>n>>m;
        vector<pair<ll,ll>> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].first;
        }

        for(int i=0;i<n;i++)
        {
            cin>>arr[i].second;
        }
        sort(arr.begin(),arr.end());
        
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            ans =max(ans,min(arr[i].second,m/arr[i].first)*arr[i].first);
        }
        for(int i=0;i<n-1;i++)
        {

            ll a1 = arr[i].first;
            ll a2 = arr[i+1].first;
            if(a2-a1>1)continue;
            ll c1 = arr[i].second;
            ll c2 = arr[i+1].second;
            ll val1 = min(m/a1,c1);
            ll val2 = min((m -val1*a1)/a2,c2);
            ll left = m - val1*a1 - val2*a2;
            ans = max(ans,val1*a1+val2*a2 +min(val1,min(left,c2-val2)));
        }

        cout<<ans<<'\n';
    }
}
#include<bits/stdc++.h>
typedef long long ll;
ll N = 1e6;
std::vector<ll> count(N+1,0),done(N+1,0);
int main()
{
    ll t;std::cin>>t;
    while(t--)
    {
        ll n;
        std::cin>>n;
        ll arr[n];
        std::set<ll> filter;
        for(ll i=0;i<n;i++)
        {
            std::cin>>arr[i];
            filter.insert(arr[i]);
        }
        ll maxElement = *(std::max_element(arr,arr+n));
        for(ll i=0;i<maxElement+1;i++){done[i]=0;count[i]=0;}
        for(auto x: arr)count[x]++;
        ll ans = (n*(n-1))/2;
        for(auto x:filter)
        {
            ll cnt = 0;
            ll dn_cnt = 0;
            if(count[x]==0)continue;
            for(ll i =1;(i*x)<=maxElement;i++)
            {
                cnt+= count[i*x];
                dn_cnt += done[i*x];
                done[i*x]  =count[i*x];
            }

            ans -= ((cnt*(cnt-1))/2 - ((dn_cnt)*(dn_cnt-1))/2);
        }
        std::cout<<ans<<'\n';
    }
}

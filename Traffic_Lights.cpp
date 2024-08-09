#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,n;cin>>x>>n;
    set<pair<ll,ll>> st;
    st.insert({x,0});
    map<ll,ll> sizes;
    sizes[x]++;
    for(int i=0;i<n;i++){
        ll num;cin>>num;
        auto x = st.lower_bound({num,INT_MIN});
        if(x->first >= num && x->second <= num){
            ll b = x->first, a= x->second;
            st.erase(x);
            st.insert({num,a});
            st.insert({b,num});
            sizes[b-a]--;
            if(sizes[b-a]==0)sizes.erase(b-a);
            sizes[b-num]++;
            sizes[num-a]++;
        }
         cout<<(--sizes.end())->first<<" ";
    }
   
}
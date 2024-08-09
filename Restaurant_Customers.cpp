#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    vector<pair<ll,ll>> vect(n);
    for(int i=0;i<n;i++)cin>>vect[i].first>>vect[i].second;
    map<ll,ll> cnt;
    ll sum = 0;
    for(auto [a,b]: vect)
    {
        cnt[a]++;
        cnt[b+1]--;
    }
    ll ans  =0 ;
    for(auto x: cnt)
    {
        sum+= x.second;
        ans = max(sum,ans);
    }
    cout<<ans;
}
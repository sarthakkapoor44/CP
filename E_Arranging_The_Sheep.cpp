#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
ll calc(ll x,ll n,string s){
    ll sum =0;
    ll j =0;
    rep(i,n){if(s[i]=='*'){sum += abs(x-i+j);j++;}}
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;
     string s;
     cin>>s;

     v indices;
     ll j=0;
     rep(i,n){if(s[i]=='*'){indices.pb(i-j);j++;}}
    // rep(i,indices.size()){cout<<indices[i]<<" ";}ce;
    if(indices.size()!=0){
    
    ll ans = min(calc(indices[indices.size()/2],n,s),calc(indices[indices.size()/2-1],n,s));
    cout<<ans;ce;}
    else{cout<<0;ce;}
    }
    return 0;
}
#include<bits/stdc++.h>
#include<unordered_map>
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
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n,q;
     cin>>n>>q;
     ll arr[n];
     ll query[q];
     rep(i,n){cin>>arr[i];}
     rep(i,q){cin>>query[i];}
     v pow_;
     rep(i,n){
        ll count=0;
        ll val =arr[i];
        while(val%2==0){count++;val/=2;}
        pow_.pb(count);
    }
  unordered_map<ll,ll> um;
  vector<ll> s1;
    rep(i,q){if(um[query[i]]==0){s1.pb(query[i]);um[query[i]]=1;}}

    rep(i,n){
        for(auto x :s1)
        {
                if(pow_[i]>=x && pow_[i]>0 && x>0){pow_[i]=x-1;ll val = x-1;arr[i]+= pow(2,val) ;}
        }
    } 
    rep(i,n){cout<<arr[i]<<" ";}ce;
    }
    return 0;
}
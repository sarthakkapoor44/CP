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
int main(){
    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vp odd;
    v total;
    rep(i,n){ll a;cin>>a;if(a%2==1){odd.pb(mp(a,i));}total.pb(a);}
   forb(i,odd.size()-1,1){if(odd[i].fi<odd[i-1].fi){odd[i-1].fi=odd[i].fi;total[odd[i-1].se]= odd[i].fi;}}
   rep(i,n){cout<<total[i]<<" ";}ce;
}
    return 0;
}
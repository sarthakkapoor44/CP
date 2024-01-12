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
     ll n,c,q;
     cin>>n>>c>>q;
     string s;
     cin>>s;
     vp copy;
     rep(i,c){
        ll a,b;cin>>a>>b;
        copy.pb(mp(a-1,b-a+1));
     }
     
     string y;
     rep(i,q){
     ll a;cin>>a;
     y.clear();y=s;ll j=0;
     ll len =y.length();
     ll erased=0;
       while(len<a && j< copy.size()){
        y+=y.substr(copy[j].fi,copy[j].se);j++;
        len += (y.substr(copy[j].fi,copy[j].se)).length();
        ll min_ =INT_MAX;
       forf(k,j,c){min_ = min(min_,copy[k].fi-erased);}
       y.erase(0,min_);
       erased +=min_;
       }
       cout<<y[a-1-erased];ce;
     }
  
    }
    return 0;
}
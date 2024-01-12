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
     ll n,x,y;
     cin>>n>>x>>y;
     string a,b;
     cin>>a>>b;
    v in;
    ll ans=0;
     rep(i,n){if(a[i]!=b[i]){in.pb(i);}}
      ll sz= in.size();
     if(in.size()%2==1){ans=-1;}
    else{
        ll count=0;
       if(2*y<x && a.length()>=3 &&in.size()==2 && in[1]==in[0]+1){
      ans= 2*y;
       }
       else{
        if(in.size()==2 && in[1]-in[0]==1 && (a.length()==2 || 2*y>=x)){ans= x;}
        else{ans = (in.size()/2)*y;}
       }
     
        }
     cout<<ans;ce;
    }
    return 0;
}
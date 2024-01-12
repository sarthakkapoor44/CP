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

ll counts(vp vect,ll mid,ll n){
ll sum=0;
    v vect2;
    rep(i,n){vect2.pb(vect[i].fi+(mid+1)*(vect[i].se));}
    srt(vect2);
    rep(i,mid+1){sum+=vect2[i];}
    return sum;
}
int main(){
     ll n,s;
     cin>>n>>s;
     vp vect;
     rep(i,n){ll num =0;cin>>num;vect.pb(mp(num,i+1));}

    ll l=0,r=n-1,mid;
  ll cq=0;
    ll final=0;
    while(l+1<r){
        mid= (l+r)/2;
        ll cost=counts(vect,mid,n);
        if(cost==s){cq=1;final =cost;break;}
        if(cost<s){
           
            l=mid;
        }
        else {
           
            r=mid;
        }
    }
   // cout<<l<<" "<<r;ce;
    if(cq){cout<<mid+1<<" "<<final;}
    else{
        ll index= l;
  ll a1= counts(vect,l-1,n);
  if(counts(vect,l,n)<=s){a1 =counts(vect,l,n);index=l+1;}
   if(counts(vect,l+1,n)<=s){a1 =counts(vect,l+1,n);index=l+2;} 
   cout<<index<<" "<<a1;
    }
    return 0;
}
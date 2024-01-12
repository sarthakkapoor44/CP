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
    ll n;
    cin>>n;
    v vect;vect.pb(-1e18);
    forf(i,1,n+1){ll a;cin>>a;vect.pb(a);}
    vect.pb(1e18);
    srt(vect);
    ll k;cin>>k;
     ll l,r;
    rep(i,k){
       cin>>l>>r;
    ll start = lower_bound(vect.begin(),vect.end(),l)-vect.begin();
   
    ll end = upper_bound(vect.begin(),vect.end(),r)-vect.begin();
    if(vect[end+1]==r){end++;}
    cout<<end-start<<" ";
    }

    return 0;
}
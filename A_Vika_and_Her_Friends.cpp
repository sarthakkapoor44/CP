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
    
ll n,m,k;
cin>>n>>m>>k;
ll v1,v2;
cin>>v1>>v2;
vp vect;
rep(i,k){ll a,b; cin>>a>>b; vect.pb(mp(a,b));}
ll cq=0;
rep(i,k){if((v1+v2)%2==(vect[i].fi+vect[i].se)%2){cout<<"NO";cq=1;break;}}
if(!cq){cout<<"YES";}ce;
    }
    return 0;
}
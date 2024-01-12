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
     ll fragments=n;
     ll splits=0;
    unordered_map<ll,ll> ump;
    unordered_map<ll,vector<int> > ip;
    v vect;   
    rep(i,n){
        ll k;cin>>k;
        rep(j,k){ll num;cin>>num;ip[i+1].pb(num);vect.pb(num);}
    }
    srt(vect);
    rep(i,vect.size()-1){ump[vect[i]]=vect[i+1];}
    rep(i,n){
        rep(j,ip[i+1].size()-1){if(ump[ip[i+1][j]]!=ip[i+1][j+1]){
            splits++; //cout<<ip[i+1][j]<<" "<<ip[i+1][j+1];ce;
        }}
       
    }

cout<<splits<<" "<<splits+n-1;
    return 0;
}
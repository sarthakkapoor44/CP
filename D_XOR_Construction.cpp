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
    ll arr[n];rep(i,n){cin>>arr[i];}
    v vect;
    ll copy;
       ll num=2;
  
 
    copy= num;
    rep(i,n-1){
        vect.pb(num^arr[i]);
        num =num^arr[i];
        }
          rep(i,n-1){if((arr[i]^arr[i+1])<=n-1){num=vect[i-1];break;}}
        cout<<copy<<" ";
        rep(i,vect.size()){cout<<vect[i]<<" ";}
    return 0;
}
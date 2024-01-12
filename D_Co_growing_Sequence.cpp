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
     ll arr[n];
     rep(i,n){cin>>arr[i];}
     ll ans[n];
     ans[0]=0;
     forf(i,1,n){
        ll val = arr[i]&arr[i-1];
        val = arr[i-1]^val;
        ans[i] = val;
        arr[i] = ans[i]^arr[i];
     }
     rep(i,n){cout<<ans[i]<<" ";}ce;
    }
    return 0;
}
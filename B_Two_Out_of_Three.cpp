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
        ll ans[n];rep(i,n){ans[i]=1;}
     ll arr[n];
     unordered_map<ll,ll> ump;
     v vect;
     rep(i,n){cin>>arr[i];
     if(vect.size()<2){if(ump[arr[i]]==1){vect.pb(i);}}
     ump[arr[i]]++;
     }
     if(n<4){cout<<-1;}
     else{
  
    if(vect.size()<2){cout<<-1;}
    else{
        ans[vect[0]]=2;
        ans[vect[1]]=3;
        rep(i,n){cout<<ans[i]<<" ";}
    }
    
     }
     
ce;
     }
    return 0;}

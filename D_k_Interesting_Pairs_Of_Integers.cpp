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
 
     ll n,k;
     cin>>n>>k;
     ll arr[n];
     ll count[100000];
     rep(i,100000){count[i]=0;}
     rep(i,n){cin>>arr[i];count[arr[i]]++;}
     v vect;
     ll ans=0;
     if(k!=0){
     rep(i,100000){if(count[i]!=0){vect.pb(i);}}
     rep(i,vect.size()){
        forf(j,i+1,vect.size()){
            if(__builtin_popcountll(vect[i]^vect[j])==k){ans+=count[vect[i]]*count[vect[j]];}
        }
     }
     }else{rep(i,100000){if(count[i]!=0){ans+= (count[i]*(count[i]-1))/2;}}}
     cout<<ans;
     ce;
    
    return 0;
}
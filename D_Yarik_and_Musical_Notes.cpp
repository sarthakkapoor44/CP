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
     vp sub;
     rep(i,n){
        ll count =0;
        ll val=arr[i];
        while(val%2==0){val/=2;count++;}
        sub.pb(mp(val,arr[i]-count));
     }
    srt(sub);
    ll j=0;
    ll val =0;
    // rep(i,n){cout<<sub[i].fi<<sub[i].se<<" ";}ce;
    while(j<=n-2){
        ll count2 =1;
    while( j<=n-2 && sub[j+1].fi==sub[j].fi && sub[j+1].se==sub[j].se){count2++;j++;}
    j++;

    val+= (count2*(count2-1))/2;
    }
    cout<<val;ce;
    }
    return 0;
}
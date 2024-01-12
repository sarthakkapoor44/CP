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
    vp sum;
    ll total =0;
    rep(i,n){ll a;cin>>a;sum.pb(mp(a,i));total+=a;}
    ll ma=0;
    
    srt(sum);
    sum.pb(mp(0,0));
    ll arr[n];
    ll i=0,last_i=0;
    while(i<n){
        ma+=sum[i].fi;
        if(sum[i+1].fi==sum[i].fi){i++;}
        else{forf(j,last_i,i+1){arr[sum[j].se]=total-ma;}i++;last_i=i;}
       }

    rep(i,n){cout<<arr[i]<<" ";}
    return 0;
}
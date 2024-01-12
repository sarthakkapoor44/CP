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
     ll arr[2*n];
     ll m = 2*n;
     rep(i,m){cin>>arr[i];}
     ll l=0,r=m-1;
     ll sum=0;
     sort(arr,arr+m);
    vp vect;
     while(l<r){
    vect.pb(mp(arr[l],arr[r]));
    l++;r--;
     }
     rep(i,vect.size()-1){
        sum += abs(vect[i].fi - vect[i+1].fi )+ abs(vect[i].se - vect[i+1].se);
     }
     cout<<sum;ce;
     rep(i,vect.size()){cout<<vect[i].fi << " "<<vect[i].se;ce;}
    
    }
    return 0;
}
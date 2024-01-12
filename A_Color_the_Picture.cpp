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
     ll arr[k];
     rep(i,k){cin>>arr[i];}
     sort(arr,arr+k);
     ll ans =0;
    // cols
    ll sum=0;
    ll flag=0;
    if(n%2==0){flag=1;}
        rep(i,k){
            ll val = arr[i]/m;
            if(val>=2){sum+=val;}
            if(val>=3){flag=1;}
        }
        if(sum>=n && flag){ans=1;}
        sum=0;flag=0;
        if(m%2==0){flag=1;}
        rep(i,k){ll val = arr[i]/n;
        if(val>=2){sum+=val;}
        if(val>=3){flag=1;}
        }
        if(sum>=m && flag){ans=1;}
     
     if(ans){cout<<"Yes";}else{cout<<"No";}ce;
    }
    return 0;
}
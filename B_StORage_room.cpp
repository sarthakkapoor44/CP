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
     ll flag=0;
     ll arr[n][n];
     ll all=0;
     rep(i,n){rep(j,n){ll a;cin>>a;arr[i][j]=a;if(a!=0)all = all|a;}}
   ll ans[n];
//  cout<<arr[0][0];
     rep(i,n){ll val = 0;rep(j,n){if(i!=j){val=arr[i][j];break;}}
     rep(j,n){if(i!=j){val = val&arr[i][j];}}
     ans[i] = val;
     }
    ll cq=1;
    ll ors=0;
    rep(i,n){ors= ors|ans[i];}
    if(ors!=all){cq=0;}
    if(n==1){cq=1;ans[0]=0;}
    if(cq){cout<<"YES";ce;rep(i,n){cout<<ans[i]<<" ";}} else{cout<<"NO";}ce;
    
    }
    return 0;
}
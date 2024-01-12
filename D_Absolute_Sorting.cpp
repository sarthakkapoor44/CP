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
     ll l=0,r=1e9;
     rep(i,n-1){
       // cout<<l<<" "<<r;ce;
        if(arr[i+1]<arr[i]){ll val;val = (arr[i]+arr[i+1])/2;if((arr[i]+arr[i+1])%2!=0){val++;} l = max(l,val);}
        else if(arr[i+1]>arr[i]){ll val2 = (arr[i]+arr[i+1])/2;r = min(r,val2);}
     }
     //cout<<l<<" "<<r;ce;
         if(l<=r){cout<<l;}else{cout<<-1;}ce;
    }
    return 0;
}
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
  
     ll n,k,x;
     cin>>n>>k>>x;
     ll arr[n];
     rep(i,n){cin>>arr[i];}
     sort(arr,arr+n);
     //rep(i,n){cout<<arr[i]<<" ";}
     //ce;
     ll groups=1;
     vector<ll> add;
    forf(i,0,n-1){
        if(arr[i+1]-arr[i]>x){
        ll gap = (arr[i+1]-arr[i]);
        ll insert=0;
        if(gap%x==0){insert = gap/x-1;}
        else{insert = gap/x;}
       add.pb(insert);
       groups++;
               }
        }
        srt(add);
        forf(i,0,add.size()){
            if(k>=add[i]){groups--;k-=add[i];}
        }
        cout<<groups;
        ce;
    
    return 0;
}
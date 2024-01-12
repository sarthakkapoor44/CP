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
     ll pos=0;
     rep(i,n){cin>>arr[i];if(arr[i]>=0){pos = 1;}}
     ll ans=0;
     if(!pos){
        ll max_ =INT_MIN;
        rep(i,n){max_ = max(max_,arr[i]);}
        ans =max_;
     }
     else{
ll start=0,end=n-1;
while(arr[start]<0){start++;}
while(arr[end]<0){end--;}
v vect;
for(int i=start;i<=end;){
    if(arr[i]>=0){vect.pb(arr[i]);i++;}
    else{ ll count =0;
    ll begin =i;
        while(arr[i]<0 && i<=end){i++;count++;}
        if(count%2==0){
            if(arr[begin]<arr[i-1]){vect.pb(arr[i-1]);}
            else{vect.pb(arr[begin]);}}
        else {if(begin!=i-1){vect.pb(arr[begin]+arr[i-1]);}else{vect.pb(arr[i-1]);}}

    }
}
   rep(i,vect.size()){cout<<vect[i]<<" ";}ce;
   }
     cout<<ans;ce;
    }
    return 0;
}
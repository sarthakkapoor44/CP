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
ll find_sums(ll start,ll end,ll arr[]){
vector<ll> ip;
forf(i,start,end){ip.pb(arr[i]);}
sort(ip.begin(),ip.end(),greater<ll>());
ll sum=0;
for(int i=0;i<ip.size();i+=2){sum+=ip[i];}
return sum;
}
int main(){
    ll n,h;
    cin>>n>>h;
    ll arr[n];
    //arr[0]=0;
    ll cq=0;
    forf(i,0,n){cin>>arr[i];}
    ll l=0;ll r=n-1;ll mid;
    ll sum  = find_sums(0,n,arr);
    //cout<<sum;
    while(l<r-1){
     mid=(l+r)/2;
    // cout<<l<<" "<<r<<" "<<mid;ce;
     ll val  = find_sums(0,mid+1,arr);
    // cout<<val;ce;
     if(val>h){r = mid;}
    else if(val==h){cq=1;break;}
    else{l=mid;}
    }
   if(cq){
    if(find_sums(0,mid+2,arr)<=h){cout<<mid+2;}
    else{cout<<mid+1;}}
  else{
    if(find_sums(0,r+2,arr)<=h){cout<<r+2;}
    else if(find_sums(0,r+1,arr)<=h){cout<<r+1;}
    else if (find_sums(0,l+2,arr)<=h){cout<<l+2;}
    else{cout<<l+1;}
    }
    return 0;
}
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
     ll arr[n],old[n];
     rep(i,n){cin>>arr[i];old[i]=arr[i];}
    //  rep(i,n){cout<<arr[i]<<" ";}ce;
     sort(arr,arr+n);
    //  rep(i,n){cout<<arr[i]<<" ";}ce;ce;
    ll count=0;
    ll i=0;
    while(old[i]!=arr[0]){count++;i++;}
    forf(j,count,n-1){if(old[j+1]<old[j]){count=-1;break;}}
    cout<<count<<endl;
  
    }
    return 0;
}
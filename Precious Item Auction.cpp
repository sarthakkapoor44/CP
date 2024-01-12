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
     ll n,k;
     cin>>n>>k;
     ll arr[n];
     rep(i,n){cin>>arr[i];}
     sort(arr,arr+n);
     ll count =0;
     ll sum=0;
     ll i= n-1;
     while(count!=k){
        sum += arr[i];
        i-=2;
        count++;
     }
     ll max =sum;
     sum=0;
     rep(i,k-1){
        sum+=arr[i];
     }
     sum += arr[n-k-1];
     ll min = sum;
    cout<<min<<" "<<max;ce;
    }
    return 0;
}
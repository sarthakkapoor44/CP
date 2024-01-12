#include<bits/stdc++.h>
#include<algorithm>
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
ll gcd__(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;
     ll arr[n];
     rep(i,n){cin>>arr[i];}
     sort(arr,arr+n);
     ll val =0;
    
     ll diff[n-1];
     rep(i,n-1){diff[i]=arr[i+1]-arr[i];}
     val = diff[0];
     rep(i,n-1){val = gcd__(val,diff[i]);}
     ll sum=0;
     ll count=1;
     ll j=n-2;
     while(arr[j]==arr[n-1]-count*val){count++;j--;}
     ll add = arr[n-1]- count*val;
     rep(i,n){sum+=abs((arr[n-1]-arr[i])/val);}
     sum += min(((arr[n-1]-add)/val),n);
     cout<<sum;ce;
    }
    return 0;
}

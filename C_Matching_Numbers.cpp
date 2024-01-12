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
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
/*ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2==0){pno;ce;}
        else{
        pyes;ce;
        ll val = n/2 +1;
        ll arr[2*n];
        rep(i,2*n){arr[i]=i+1;}
        // rep(i,2*n){cout<<arr[i]<<" ";}ce;
         rep(i,val){cout<<arr[i]<<" "<<arr[2*n+i-val];ce;}
         forf(i,val,n){cout<<arr[i]<<" "<<arr[i-val+n];ce;}
        }
    }
return 0;
}
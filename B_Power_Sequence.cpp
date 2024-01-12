#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
const ll MODN= 1e9 + 7;
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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];rep(i,n)cin>>arr[i];
        sort(arr,arr+n);
        ll sum  =0;
        rep(i,n){sum+=arr[i];}
      ll val =1e18;
        ll power = 9/(n-1);
        ll high =1;
    rep(i,power+1)high*=10;

        forf(i,1,high){
            ll num= (long long)(pow(i,n)-1)/(i-1);
            val = min(abs(sum-num),val);
            // cout<<val;ce;
        }
        cout<<sum;ce;
        cout<<(long long)((pow(10000,3))-1)/(10000-1);ce;
        cout<<val;ce;
    }
return 0;
}
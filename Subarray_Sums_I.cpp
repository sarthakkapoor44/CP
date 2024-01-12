#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end
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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n,k;
        cin>>n>>k;
        v suffix;suffix.pb(0);
        forf(i,1,n+1){ll num;cin>>num;suffix.pb(suffix[i-1]+num);}
        ll ans =0;
        // rep(i,n+1){cout<<suffix[i]<<" ";}ce;
        forf(i,1,n+1){
            if(suffix[i]>=k){
                v::iterator itr = lower_bound(suffix.begin(),suffix.begin()+i,suffix[i]-k);
                ll index= itr-suffix.begin();
                if(index<i && suffix[index]==suffix[i]-k){ans++;}
            }
        }
        cout<<ans;ce;
    }
return 0;
}
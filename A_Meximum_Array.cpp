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
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];rep(i,n){cin>>arr[i];}
        ll count[n+1];
        memset(count,0,sizeof(count));
        rep(i,n){count[arr[i]]++;}
        v ans;
        ll mx =0;
        rep(i,n+1){if(count[i]==0){mx = i;break;}}
        set<ll> mex;
        ll next_mx =mx;
        rep(i,n){
            count[arr[i]]--;
            if(count[arr[i]]==0 && arr[i]<mx){next_mx = min(next_mx,arr[i]);}
            if(arr[i]<mx){mex.insert(arr[i]);}
            if(mex.size()==mx){
                ans.pb(mx);
                mx = next_mx;
                mex.clear();
            }

        }
        cout<<ans.size();ce;
        rep(i,ans.size()){cout<<ans[i]<<" ";}ce;
    }
return 0;
}
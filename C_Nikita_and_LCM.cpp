///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n);
        map<ll,ll> freq;
        rep(i,n)
        {
            cin>>arr[i];
            freq[arr[i]]++;
        }
        ll cq=0;
        ll mx = *max_element(arr.begin(),arr.end());
        ll ans =0;
        rep(i,n)
        {
            if((mx%arr[i])){cq=1;break;}
        }
        if(cq)ans=n;
        else 
        {
            set<ll> factors;
            for(int i=2;i*i<=mx;i++)
            {
                if(!(mx%i))
                {
                    factors.insert(i);factors.insert(mx/i);
                } 
            }
            
            for(auto x:factors)
            {
                if(!freq[x])
                {
                    ll temp =0;
                    v div;
                    rep(i,n)
                    {
                        if(!(x%arr[i])){temp++;div.pb(arr[i]);}
                    }
                 if(temp)
                 {  
                    ll val = div[0];
                    forf(i,1,div.size())
                    {
                        val = (val*(div[i]))/(gcd(val,div[i]));
                    }
                    if(val == x)ans=max(ans,temp);
                }
                }
            }
        }
        cout<<ans;ce;
    }

    return 0;
}

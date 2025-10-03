///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
   tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

ll mod_inv(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = mod_inv(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vll a(n),b(n);
        rep(i,n)cin>>a[i];
        rep(i,n)cin>>b[i];
        ost bit1,bit2;
        ll ans = 1;
        rep(i,n)
        {
            bit1.insert({a[i],-i});
            bit2.insert({b[i],-i});
            // cout<<*bit1.find(a[i])
        }

        rep(i,n)
        {
            (ans *= min(bit1.find_by_order(i)->fi,bit2.find_by_order(i)->fi))%=modn;
        }
        cout<<ans<<" ";
        rep(i,q)
        {
            ll type,x;
            cin>>type>>x;
            x--;
            if(type == 1)
            {
                ll old_val = a[x];
                a[x]++;
                bit1.erase(bit1.lower_bound({old_val,-INF}));
                bit1.insert({a[x],-(x+i+1)});
                ll new_idx = bit1.order_of_key({a[x],-(x+i+1)});
                ll x1,y1;
                ll b_val = bit2.find_by_order(new_idx)->fi;
                ll gcd = mod_inv(min(old_val,b_val),modn,x1,y1);   
                if(gcd==1)
                {
                    (ans*= (x1+modn)%modn)%=modn;
                    (ans *=(min(a[x],b_val))%modn)%=modn;
                }
            }
            else 
            {   
                ll old_val = b[x];
                b[x]++;
                bit2.erase(bit2.lower_bound({old_val,-INF}));
                bit2.insert({b[x],-(x+i+1)});
                ll new_idx = bit2.order_of_key({b[x],-(x+i+1)});
                ll x1,y1;
                ll a_val = bit1.find_by_order(new_idx)->fi;
                ll gcd = mod_inv(min(old_val,a_val),modn,x1,y1);   
                
                if(gcd==1)
                {
                    (ans*= (x1+modn)%modn)%=modn;
                    (ans *=(min(b[x],a_val))%modn)%=modn;
                }

            }
            cout<<ans<<" ";

        }
        cout<<endl;
        
    }

    return 0;
}
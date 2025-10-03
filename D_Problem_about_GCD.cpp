///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
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
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
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
        ll l,r,g;
        cin>>l>>r>>g;
        ll left = ((l+g-1)/g);
        ll right = (r/g);
        ll ans1 = 0,ans2 =0;
        // cout<<left<<" "<<right<<endl;
        if(r < g ||  left >  right)
        {
            cout<<-1<<" "<<-1;
        }
        else if(left == right)
        {
            if(left ==1)cout<<g<<" "<<g;
            else cout<<-1<<" "<<-1;
        }
        else
        {
            ll ans_dist  = 0 ;
            left = max(left,1ll);
            right = max(right,1ll);
            // cout<<left<<" "<<right<<endl;

            for(ll i = left;i<=min(right,left+100ll);i++)
            {
                for(ll j = right;j>=max(left,right - 100ll);j--)
                {
                    if(abs(i-j) <  ans_dist) break;
                    if(i != j and __gcd(i,j) == 1)
                    {
                        // cout<<i<<" "<<j<<endl;
                        if(abs(i-j) > ans_dist)
                        {
                            // cout<<i*g<<" "<<j*g<<endl;
                            ans_dist = abs(i-j);
                            ans1 = i;
                            ans2 = j;
                        }
                    }
                }
            }
            cout<<ans1*g<<" "<<ans2*g;
        }
        cout<<endl;
        
    }

    return 0;
}
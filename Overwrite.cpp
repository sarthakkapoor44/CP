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
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll a(n),b(m);
        rep(i,n)cin>>a[i];
        rep(i,m)cin>>b[i];
        ll mnb=*min_element(all(b)),idxb=0;
        rep(i,m)if(b[i]==mnb){idxb = i;break;}
        vll nb(m);
        for(int i=idxb;i<m+idxb;i++)
        {
            nb[(i-idxb)]= b[(i)%m];
        }
        ll flag=0;
        if(m==1)rep(i,n)if(a[i]>mnb)a[i]=mnb;
        if(m!=1)
        {
        ll pos2 = -1;
        rep(i, n - m + 1) {
            if (a[i] > mnb) {
                pos2 = i;
                break;
            }
        }
        if (pos2 != -1) {
            forf(j, pos2, n - m + 1) {
                a[j] = mnb;
            }
            rep(j, m) {
                a[n - m + j] = nb[j];
            }
        } else if (a[n - m] == mnb) {
            ll cmpFlag = 0;
            rep(j, m) {
                if (a[n - m + j] > nb[j]) {
                    cmpFlag = 1; 
                    break;
                } else if (a[n - m + j] < nb[j]) {
                    cmpFlag = 2; 
                    break;
                }
            }
            if (cmpFlag == 1) {
                rep(j, m) {
                    a[n - m + j] = nb[j];
                }
            }
        }
    }
    out(a);
    }
    return 0;
}

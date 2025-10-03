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
        ll n,m;
        cin>>n>>m;
        vll arr(n),ques(m);
        rep(i,n)cin>>arr[i];
        rep(i,m)cin>>ques[i];         
        srt(ques);
        vll cnt(m,0);
        ll kevin = arr[0];
        rep(i,n)
        {
            if(arr[i] > kevin)
            {
                ll idx = upper_bound(all(ques),arr[i])-ques.begin();
                idx--;
                if(idx>=0)
                {
                    cnt[idx]++;
                }
            }
        }
        ll val =0 ;
        forb(i,m-1,0)
        {
            val+=cnt[i];
            cnt[i] = val;
        }
        // out(ques);
        ll idx = upper_bound(all(ques),kevin)-ques.begin();
        idx--;
        forf(i,1,m+1)
        {
            ll rem = m%i;
            ll temp = (idx+1)/i;
            ll pre_rem = (idx+1)%i;
            ll nidx = temp*i + rem+pre_rem;
            if(nidx< m)
            {
                // temp+= cnt[nidx]+1;
                // nidx += (i - pre_rem); 
                int j =nidx;
                for(;j<m;j+= i)
                {
                    temp+= cnt[j]+1;
                }
                j-=i;
                if(m - j -1 + pre_rem == i)
                {
                    if(j+1<m)temp+= cnt[j+1]+1;
                }

            }
            cout<<temp<<" ";
        }
        ce;
        
    }

    return 0;
}


bool is_prime[MAXN];
void sieve_of_eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (ll j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
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
#define pyes cout<<"YES";
#define pno cout<<"NO";
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
 
const ll m = 1e9 + 9;
const ll MAXN = 1000001;
const ll modn = 998244353;
const ll p = 53;
 
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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
  
    {	//Lesgooooooo!!!!
        string s;
        cin>>s;
        ll n = s.length();
        vll p_pow(n); 
        p_pow[0] = 1; 
        forf(i,1,n) p_pow[i] = (p_pow[i-1] * p) % m;
        vll h(n + 1, 0); 
        rep(i,n)h[i+1] = (h[i] + (s[i] - 'a' ) * p_pow[i]) % m; 
    
        forb(i,n-1,1){
            if(s[i]==s[0] && 2*i<n && s[2*i]== s[i])
            {
                // cout<<i<<" "<<s[i]<<" "<<s[2*i];ce;
                if(((h[i]*p_pow[i])%m) == (h[2*i]-h[i]+m)%m)
                {
                    // for(int j=0;j<i;j++)cout<<s[j];ce;
                    // forf(j,i,2*i)cout<<s[j];ce;
                    pyes;ce;
                    cout<<s.substr(i);
                    return 0;
                }

            }
        }
        pno;
    }

    return 0;
}

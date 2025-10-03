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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        ll cq = 1;
        vll nums;
        if(m>n)
        {
            cq=0;
        }
        else if(m==n)cq=1;
        else
        {
            bitset<63> a = n; 
            bitset<63> b = m;
            nums.pb(n);
            if(__builtin_popcount(n)==1)cq=0;
            else
            {
                ll msb1=62,msb2=62,msbb=62,cnt=0;
                for(int i=62;i>=0;i--)
                {
                    if(a[i]==1 && cnt==0)
                    {
                        msb1 =i;
                        cnt++;
                    } 
                    else if(a[i] ==1 && cnt==1)
                    {
                        msb2 =i;
                        cnt++;
                    }
                }
                if(b[msb1] ==1)
                {
                    nums.pb(m);
                }
                else
                {
                
                    for(int i=62;i>=0;i--)
                    {
                        if(b[i]){msbb=i;break;}
                    }
                    if(msbb > msb2 && msbb<msb1 )cq=0;
                    else
                    {
                        // cout<<msb1;ce;
                        ll val = n^(1ll<<msb1);
                        // cout<<val;ce;
                        if(msb2!=msbb)val^= (1ll<<msb2);
                        // cout<<val;ce;
                        val^=m;
                        // cout<<val;ce;
                        if(val)nums.pb((n^(val)));
                        ll temp = (n^val);
                        nums.pb(((temp^(1ll<<msb1))^((msb2==msbb)?0:(1ll<<msb2))));
                        cq=1;
                    }
                }
              
            }
        }  

        if(cq)
        {
            cout<<nums.size()-1;ce;
            out(nums);
        }
        else
        {
            cout<<-1;ce;
        }
    }

    return 0;
}


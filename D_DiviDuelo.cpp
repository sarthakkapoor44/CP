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
#define pll pair<ll,ll>
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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vp fact;
        ll cnt =0;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        if(cnt)fact.pb({2,cnt});
        for(ll i=3;i*i<=n;i+=2){
            cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            if(cnt)fact.pb({i,cnt});
        }
        if(n>1)fact.pb({n,1}); 
        // debug(fact);
        ll total_num_fact = 1;
        for(auto x:fact)
        {
            total_num_fact*=(x.se+1);
        }   
        if(total_num_fact%2==1 || fact.size() > 2)
        {
            cout<<"N"<<'\n';return 0;
        }
        else
        {
            if(fact.size()==1)
            {
                
                cout<<"Y"<<'\n';
                return 0;
            }
            else if(fact.size()==2)
            {
                if(fact[0].se == 1 and fact[1].se == 1)
                {
                    cout<<"Y"<<'\n';
                    return 0;
                }
                else  if(fact[0].se%2 + fact[1].se%2 == 1)
                {
                    if((fact[0].se%2 == 1 and fact[1].se==1) || (fact[1].se%2 == 1 and fact[0].se==1))
                    cout<<"Y"<<'\n';
                    else cout<<"N"<<'\n';
                    return 0;
                }
                else
                {
                    cout<<"N"<<'\n';
                    return 0;
                }
            }
        }
        cout<<"N"<<'\n';
    }

    return 0;
}

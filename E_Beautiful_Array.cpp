///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        map<ll,map<ll,ll>> mods;
        rep(i,n)
        {
            int cnt = ++mods[arr[i]%k][arr[i]/k];
            mods[arr[i]%k][arr[i]/k] = cnt%2;
            if(mods[arr[i]%k][arr[i]/k]==0)mods[arr[i]%k].erase(arr[i]/k);
        }
        ll oc =0;
        bool fl =0;
        ll ans  = 0;
        for(auto x:mods)
        {
            oc+= (x.second.size()%2);
            if((oc && !(n%2)) ||  (oc>1 &&(n%2))){fl=1;break;}
            vector<int> diff;
            // cout<<x.first<<"->";
            for(auto y: x.second)
            {
                // cout<<y.first<<" ";
                diff.push_back(y.first);
            }
            // ce;
            ll len = diff.size();
            ll val = 0;
            if(diff.size()%2)
            {
                ll val1=0;
                vll prefix(len,0),suffix(len,0);
                rep(i,len)
                {
                    if((i%2))prefix[i] = ( i?prefix[i-1]:0)+ diff[i];
                    else prefix[i]=( i?prefix[i-1]:0)-diff[i];
                }
                forb(i,len-1,0)
                {
                    if((i%2))suffix[i] = ( (i+1<len)?suffix[i+1]:0)- diff[i];
                    else suffix[i]=( (i+1<len)?suffix[i+1]:0)+ diff[i];
                }
                // for(auto p:prefix)cout<<p<<" ";ce;
                // for(auto q:suffix)cout<<q<<" "; ce;
                val=INF;
                for(int i=0;i<len;i+=2)
                {
                    val = min(val,( (i?prefix[i-1]:0)) + ((i+1<len)?suffix[i+1]:0));
                }
             
            }
            else
            {
                for(int i=0;i<len;i+=2){
                    val+= (diff[i+1]-diff[i]);
                }
            }
            ans+=val;
        }
        if(fl)cout<<-1;
        else{cout<<ans;}
        ce;
    }

    return 0;
}

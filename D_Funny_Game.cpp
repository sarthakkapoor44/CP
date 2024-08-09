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
vector<ll> parent,ranks;
ll find_set(ll a){
    if(a== parent[a])return parent[a];
    return parent[a] = find_set(parent[a]);
}

void union_set(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if(ranks[a]<ranks[b])swap(a,b);
    ranks[a] += ranks[b];
    parent[b] =a;

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
        ll n;
        cin>>n;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        parent.clear();ranks.clear();
        parent.resize(n);ranks.resize(n);
        for(int i=0;i<n;i++){parent[i]=i;ranks[i]=1;}
        vector<pair<ll,ll>> edge;
        for(int i=n-1;i>=1;i--)
        {
            map<ll,set<ll>> mods;
            for(int j =0 ;j<n;j++)
            {
                if(mods.count(arr[j]%i)){
                    ll temp =  *(mods[arr[j]%i].begin());
                    if(find_set(temp)!=find_set(j))mods[arr[j]%i].insert(j);
                }
                else mods[(arr[j]%i)].insert(j);
            }
            // cout<<i<<endl;
            for(auto x: mods)
            {
                // cout<<x.fi<<"->";
                // for(auto y:x.se)cout<<y<<" ";ce;
                if(x.se.size()>=2)
                {
                    auto a = x.se.begin();
                    auto b = ++x.se.begin();
                    edge.push_back({*a,*b});
                    union_set(*a,*b);
                    break;
                }
            }
        }
        pyes;ce;
        reverse(edge.begin(),edge.end());
        for(auto x:edge)
        {
            cout<<x.fi+1<<" "<<x.se+1;ce;
        }
    }

    return 0;
}

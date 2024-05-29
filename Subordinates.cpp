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
const ll MAXN = 200001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
vector<vector<ll> > adj(MAXN);
ll calc_subtree(ll pos,ll parent,v &subtree)
{
    if(subtree[pos])return subtree[pos];
    // subtree[pos]=1;
    for(auto x:adj[pos])
    {
        if(x!=parent)
        {
            subtree[pos]+=  1+calc_subtree(x,pos,subtree);
        }
    }
    return subtree[pos];
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n);
        arr[0]=-1;
        
        forf(i,1,n)
        {
            cin>>arr[i];
            arr[i]--;
            adj[i].pb(arr[i]);
            adj[arr[i]].pb(i); 
        }
        // for(auto x:arr)cout<<x<<" ";ce;
        v subtree(n,0);
        calc_subtree(0,-1,subtree);
        for(auto x: subtree)cout<<x<<" ";ce;
    }

    return 0;
}

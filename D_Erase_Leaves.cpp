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
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
ll recursion(ll idx, vector<vector<ll>  >&adj,ll parent, vector<ll> &sub){
    
    
        for(auto x:adj[idx]){
          if(x!=parent)  sub[idx] += recursion(x,adj,idx,sub);
        }
    
    return sub[idx];
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    

    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<vector<ll>  >adj(n);
        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        // vector<bool> visited(n,false);
        vector<ll> sub(n,1);
        recursion(0,adj,-1,sub);
        ll val=0;
        ll num =-INF;
        for(auto x:adj[0]){num = max(num,sub[x]);val +=sub[x];}
        val-=num;
        cout<<val+1;ce;
    }

    return 0;
}

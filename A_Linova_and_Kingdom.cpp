///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
ll dfs(ll pos,unordered_map<ll,vector<ll> >&adj,vector<bool> &visited,v &nodes,ll last,ll &len,ll dist[])
{
if(visited[pos]==false){
    // cout<<pos;ce;
    visited[pos] =true;
    dist[pos]=len;
    
    if(adj[pos].size()==1 && pos!=1){return nodes[pos]=0;}
    else{
        for(auto x: adj[pos]){
              len++;
            if(x!=last){
               
                nodes[pos]+=dfs(x,adj,visited,nodes,pos,len,dist)+1;
                
                }
            len--;
        }
    }
   
}
return nodes[pos];
}
int main() {
      // we need to write a function that calculates the number of nodes in the subtee rooted at that node
      //Lesgooooooo!!!!
        ll n,k;
        scanf("%lld %lld",&n,&k);
        unordered_map<ll,vector<ll> >adj;
        rep(i,n-1){ll a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);}
        vector<bool> visited(n+1,false);
        v nodes(n+1,0);
        ll dist[n+1];
        rep(i,n+1){dist[i]=0;}
        ll len=0;
        dfs(1,adj,visited,nodes,0,len,dist);
        // forf(i,1,n+1){cout<<dist[i]<<" ";}ce;
        // forf(i,1,n+1){cout<<nodes[i]<<" ";}ce;
     ll sum=0;
        v val;
        rep(i,n){val.pb(dist[i+1]-nodes[i+1]);}
        sort(all(val),greater<ll>());
        rep(i,k){sum+=val[i];}
        cout<<sum;ce;

    return 0;
}

//-----Smallest prime factor----------//
/*
void sieve() {
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        spf[i] = i;

    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
*/


//-----GCD----------//
/*
ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}
*/

//-----Sieve of eratosthenes----------//
/*
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
*/
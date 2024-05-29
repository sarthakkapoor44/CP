///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
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
void dfs(ll vertex,ll temp,v &cats,unordered_map<ll,vector<ll> > &adj,ll n,ll m, vector<bool> &visited,ll &ans)
{
    if(visited[vertex]==false)
    {
    visited[vertex]=true;
    ll t_copy= temp;
    if (cats[vertex]){temp++;}
    else temp=0;
    if(temp>m){temp=t_copy;return;}
    if(adj[vertex].size()==1 && vertex!=1){ans++;}
    // cout<<vertex;ce;
    for (auto x : adj[vertex])
    {
        dfs(x,temp,cats,adj,n,m,visited,ans);
    }
    temp= t_copy;
    return;

    }   
}
int main() {
    
    {   //Lesgooooooo!!!!
        ll n,m;
        scanf("%lld %lld",&n,&m);
        v cats(n+1,0);forf(i,1,n+1){scanf("%lld",&cats[i]);}
        unordered_map<ll,vector<ll> > adj;
        ll a,b;
        rep(i,n-1)
        {
            scanf("%lld %lld",&a,&b);
            adj[a].pb(b);adj[b].pb(a);
        }
        vector<bool> visited(n+1,false);
        ll temp=0,ans=0;
        visited[0]=true;
        dfs(1,temp,cats,adj,n,m,visited,ans);
        
        printf("%lld",ans);ce;
    }

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
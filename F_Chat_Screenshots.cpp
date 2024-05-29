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
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
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
void dfs(ll index,unordered_map<ll,set<ll> > &adj,v &visited,ll &ans){
    if(visited[index]==1){ans=0;return;}
    if(visited[index]==0){
        visited[index]=1;
        for(auto x:adj[index]){
            dfs(x,adj,visited,ans);
        }
        visited[index]=2;
    }
    return;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,k;
        scanf("%lld %lld",&n,&k);
        unordered_map<ll,set<ll> > adj;
        ll ans=1;
        rep(i,k){
            ll arr[n];
            rep(i,n){
                cin(arr[i]);
            }
            forf(i,1,n-1){
                adj[arr[i]].insert(arr[i+1]);
            }
           } 
        v visited(n+1,0);
        rep(i,n)
        {   
            if(!visited[i])dfs(i,adj,visited,ans);
            if(!ans){break;}
        }
    if(ans){pyes;}else{pno;}ce;
    }

    return 0;
}


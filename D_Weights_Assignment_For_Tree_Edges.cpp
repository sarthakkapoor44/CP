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
double max_val  =-100.00000;
void dfs(int pos,int max_len,vector<vector<pair<int,double> > > &adj,double init,int curr_len)
{

  curr_len++;
  if(curr_len==max_len+1 ){if(pos==0)max_val=max(max_val,init);return;}
  
  for(int i=0;i<3;i++){
    int x = adj[pos][i].fi;
    double val = adj[pos][i].se;
    dfs(x,max_len,adj,init*val,curr_len+1);
    }
  return ;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // vertices 0,1,2,3
    // 0 -> shell
    // 1 -> pizza
    // 2 -> wasabi
    // 3 -> snowball
    vector<vector<pair<int,double> > > adj(4);
    adj[0].pb(mp(1,1.41));
    adj[0].pb(mp(2,0.61));
    adj[0].pb(mp(3,2.18));
    adj[1].pb(mp(2,0.48));
    adj[1].pb(mp(3,1.52));
    adj[1].pb(mp(0,0.71));
    adj[2].pb(mp(0,1.56));
    adj[2].pb(mp(1,2.05));
    adj[2].pb(mp(3,3.26));
    adj[3].pb(mp(0,0.46));
    adj[3].pb(mp(1,0.64));
    adj[3].pb(mp(2,0.3));
    forf(i,1,6)dfs(0,i,adj,1.00000,0);
    cout<<max_val;ce;
    return 0;
}

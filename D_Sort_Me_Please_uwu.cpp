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


vector<pair<ll, ll> > findMinSwap(vector<ll> &arr){
    ll n = arr.size();
    vector<pair<ll, ll> > graph(n), swaps;
    for (ll i = 0; i < n; i++)
    {
        graph[i].first = arr[i];
        graph[i].second = i;
    }
    sort(graph.begin(), graph.end());
    ll minimum_swaps = 0;
    for (ll i = 0; i < n; )
    {
        if (graph[i].second == i)
        {
            ++i;
            continue;
        }
        else
        {
            swap(graph[i].first, graph[graph[i].second].first);
            swaps.push_back(mp(graph[i].second, i));  // Record the swap indices

            swap(graph[i].second, graph[graph[i].second].second);
            if (graph[i].second == i)
            {
                ++i;
            }
            ++minimum_swaps;
        }
    }
    return swaps;
}


int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
  
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vp arr(n);
        vector<vector<pair<ll,ll> > >adj(n);
        rep(i,n)
        {
            cin>>arr[i].se;
            arr[i].se= arr[i].se;
        } 
        rep(i,n)
        {

            cin>>arr[i].fi;
            adj[arr[i].se-1].pb(mp(arr[i].fi,i));

        }      
        
            ll moves=0;
            vp ans;
            rep(i,n)
            {
                if(adj[i].size())
                {
                v temp;
                rep(j,adj[i].size())temp.pb(adj[i][j].fi);
                 vp idx =   findMinSwap(temp);
                 rep(k,idx.size()){ans.pb(mp(adj[i][idx[k].fi].se,adj[i][idx[k].se].se));}
                 moves+=idx.size();
                }
            }
            rep(i,moves){
                swap(arr[ans[i].fi],arr[ans[i].se]);
            }
            ll cq=1;
            rep(i,n-1)
            {
                if(arr[i+1].fi<arr[i].fi){cq=0;break;}
            }
            if(cq){
            cout<<moves;ce;
            rep(i,moves){cout<<ans[i].fi<<" "<<ans[i].se;ce;}
            }else{cout<<-1;ce;}
        
    }

    return 0;
}

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
vector<vector<ll> >adj;
vector<ll>  parent,in,out;
ll T;
void dfs(ll pos,ll par)
{
    T++;
    in[pos]=T;
    parent[pos] =par;
    for(auto x:adj[pos])
    {
        if(x==par)continue;
        dfs(x,pos);
    }
    T++;
    out[pos]=T;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;

        adj.clear();
        in.clear();
        out.clear();
        adj.resize(n);
        in.resize(n);
        out.resize(n);
        parent.clear();
        parent.resize(n);

        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        T= 0;
        dfs(0,-1);
        parent[0]=0;
        rep(i,m)
        {
            bool cq=1;
            ll len;cin>>len;
            set<ll> arr;
            rep(j,len)
            {
                ll num;cin>>num;
                num--;arr.insert(parent[num]);
            }
            vp in_temp,out_temp;
            for(auto x:arr)
            {
                in_temp.pb(mp(in[x],x));
                out_temp.pb(mp(out[x],x));
            }
            srt(in_temp);
            srt(out_temp);
            stack<ll> st;
            for(auto x:in_temp){st.push(x.se);}
            for(auto x:out_temp){if(x.se==st.top()){st.pop();}else{cq=0;break;}}
            if(cq){pyes;}
            else pno;
            ce;
        }
    }

    return 0;
}

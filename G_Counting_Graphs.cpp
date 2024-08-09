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
vector<ll> parent,ranks;
void make_set(ll &a)
{
    parent[a] =a;
    ranks[a]=1;
    return ;
}
ll find_set(ll a)
{
    if(a==parent[a])return a;
    return parent[a] = find_set(parent[a]);
}


void union_set(ll a,ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(ranks[a]<ranks[b])swap(a,b);
    ranks[a]+=ranks[b];
    parent[b]=a;
    return;
}

ll binpow(ll a, ll b) {
    a %= modn;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % modn;
        a = a * a % modn;
        b >>= 1;
    }
    return res;
}

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,s;
        cin>>n>>s;
        vector<vector<ll> > edge_list;
        parent.clear();
        parent.resize(n);
        ranks.clear();
        ranks.resize(n);
        rep(i,n-1)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            edge_list.pb({w,a-1,b-1});
        }  
        sort(all(edge_list));
        rep(i,n)make_set(i);
        ll ans=1;
        rep(i,n-1)
        {
            ll val = s - edge_list[i][0];
            ll a = edge_list[i][1];
            ll b = edge_list[i][2];
            ll val1 =  find_set(a);
            ll val2 =  find_set(b);
            (ans*= binpow(val+1,ranks[val1]*ranks[val2]-1))%=modn;
            union_set(a,b);
        }
        cout<<ans;ce;
    }

    return 0;
}

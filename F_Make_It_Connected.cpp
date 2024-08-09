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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<ll >> edge_list;
        vector<ll> arr(n);
        parent.clear();
        ranks.clear();
        parent.resize(n);
        ranks.resize(n);
        rep(i,n)cin>>arr[i];
        ll min_elt = min_element(all(arr))-arr.begin();
        forf(i,0,n)
        {   
            if(i!=min_elt)edge_list.push_back({arr[min_elt]+arr[i],min_elt,i});
        }
        rep(i,m)
        {
            ll a,b,w;cin>>a>>b>>w;
            a--;b--;
            edge_list.push_back({w,a,b});
        }

        rep(i,n)make_set(i);
        sort(edge_list.begin(),edge_list.end());
        ll ans  =0;
        for(int i=0;i<edge_list.size();i++)
        {
            ll a  = edge_list[i][1];
            ll b  = edge_list[i][2];
            ll w  = edge_list[i][0];
            // cout<<a+1<<" "<<b+1<<" "<<w;
            if(find_set(a)!=find_set(b))
            {
                // cout<<" in";
                ans+= w;
                union_set(a,b);
            }
            // ce;
        }
        cout<<ans;ce;

    }

    return 0;
}

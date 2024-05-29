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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {   //Lesgooooooo!!!!
        ll w,h,n;
        cin>>w>>h>>n;
        set<ll> row,col;
        map<ll,ll> row_dist,col_dist;
        row_dist[h]++;
        col_dist[w]++;

        row.insert(0);row.insert(h);col.insert(0);col.insert(w);
        rep(i,n)
        {
            char type;ll dist;cin>>type>>dist;
            if(type=='H')
            {
                auto x =  row.lower_bound(dist);
                ll after  = *x - dist;
                ll before = dist - *(--x);
                row_dist[after+before]--;
                if(!(row_dist[after+before]))row_dist.erase(after+before);
                row_dist[after]++;
                row_dist[before]++;
                row.insert(dist);
            }
            else
            {
                auto y =  col.lower_bound(dist);
                ll after  = *y -dist;
                ll before = dist  - *(--y);
                col_dist[after+before]--;
                if(!(col_dist[after+before]))col_dist.erase(after+before);
                col_dist[after]++;
                col_dist[before]++;
                col.insert(dist);
            }
            auto a = *(--col_dist.end());
            auto b = *(--row_dist.end());
            cout<<(a.fi*b.fi);
            ce;
        }        
        
    }

    return 0;
}

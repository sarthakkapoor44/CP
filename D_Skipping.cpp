///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
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
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll scores(n),arr(n);
        rep(i,n)cin>>scores[i];
        rep(i,n)cin>>arr[i];
        vector<ll> dist(n,INF);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        pq.push({0,0});// penalty,pos
        dist[0] =0 ;
        while(!pq.empty())
        {
            ll top = pq.top().second;
            ll curr_dist = pq.top().first;
            pq.pop();
            if(curr_dist> dist[top])continue;
            if(top-1>=0 && dist[top-1]> curr_dist)
            {
                dist[top-1] = curr_dist;
                pq.push({curr_dist,top-1});
            }
            if(dist[arr[top]-1]> curr_dist+ scores[top])
            {
                dist[arr[top]-1]= curr_dist+ scores[top];
                pq.push({dist[arr[top]-1],arr[top]-1});
            }
        }
        // debug(dist);
        ll ans = 0;
        ll sum = 0;
        rep(i,n)
        {
            sum+= scores[i];
            // sum -= dist[i];
            ans = max(ans,sum-dist[i]);
        }
        cout<<ans;ce;
    }
   

    

    return 0;
}

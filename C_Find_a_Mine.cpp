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
        ll n,m;
        cin>>n>>m;
        cout<<"?"<<" "<<1<<" "<<1;ce;
        cout.flush();
        ll dist,dist1,dist2,dist3;
        cin>>dist;
        
        pair<ll,ll> pt1= {min(n,1+dist),max(2+dist-n,1ll)},pt2 = {max(1ll,2+dist-m),min(m,dist+1)},ans;
        cout<<"?"<<" "<<pt1.fi<<" "<<pt1.se;ce;
        cout.flush();
        cin>>dist1;
        cout<<"?"<<" "<<pt2.fi<<" "<<pt2.se;ce;
        cout.flush();
        cin>>dist2;
        ll cq= 0 ;
        if((dist1%2)==0)
        {
            cout<<"?"<<" "<<pt1.fi - dist1/2<<" "<<pt1.se + dist1/2;ce;
            cout.flush();
            cin>>dist3;
            if(dist3==0)
            {
                ans = {pt1.fi - dist1/2,pt1.se + dist1/2};
                cq=1;
            }
        }
        if(!cq && (dist2%2)==0)
        {
            ans = {pt2.fi + dist2/2,pt2.se - dist2/2};
        }
        cout<<"!"<<" "<<ans.fi<<" "<<ans.se;ce;
        cout.flush();
    }

    return 0;
}

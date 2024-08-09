///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    
    {	//Lesgooooooo!!!!
        ll a,b;
        ll c,d;
        cin>>a>>b>>c>>d;
        ll p1 = (a+b)%2;
        if(a+b<0){p1 = (2-(abs(a+b)%2))%2;}
        ll dx = abs(a-c);
        ll dy = abs(b-d);
        ll ans =min(dx,dy);
        // cout<<dx<<" "<<dy;ce;
        ll p2 = (c+d)%2;
        if(c+d<0){p2 = (2-(abs(c+d)%2))%2;}
        if(dy>dx)
        {
            ans+=(dy-dx);
        }
        else if(dx>dy)
        {
            ll dist =dx-dy;
            ans+= dist/2;
            if(p1!=p2)
            {
                if(p1==1)
                {
                    if(c>a)
                    {
                        ans++;
                    }
                }
                else
                {
                    if(c<a)ans++;
                }
            }
        }
        cout<<ans;ce;
    }

    return 0;
}

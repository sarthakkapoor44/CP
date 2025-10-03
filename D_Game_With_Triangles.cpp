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
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll a(n),b(m);
        ll laptr = 0,raptr = n-1,lbptr = 0,rbptr = m-1;
        rep(i,n)cin>>a[i];
        rep(i,m)cin>>b[i];
        if(n+m<3)
        {
            cout<<0;
            ce;
            continue;
        }
        srt(a);srt(b);
        ll x = 0,y = 0;
        // vll ans;
        ll l = 0,r = n-1;
        // vll d1,d2;
        vll s1(1),s2(1);
        ll pre = 0 ;
        ll lst= -1;
        while(l<r)
        {
            // d1.pb(a[r]-a[l]);
            s1.pb(a[r]-a[l] + pre);
            pre+= a[r] - a[l];
            r--;
            l++;
        }
        l = 0;r = m-1,pre =0;  
        while(l<r)
        {
            s2.pb(b[r]-b[l] + pre);
            pre+= b[r] - b[l];
            // d2.pb(b[r]-b[l]);
            r--;
            l++;
        }
        l = 0,r= 0 ;
        vll ans;
        rep(j,max(n,m)+1)
        {
            ll sum1=0,sum2 = 0;
            ll cq1 = 0,cq2 = 0;
            
            y++;
            l++;
            if(2*x+y <= m && 2*y+x<=n)
            {
                sum1 = s1[l]+s2[r];
                cq1 = 1;
            }
            l--;
            y--;
            
            x++;
            r++;
            if(2*x+y <= m && 2*y+x<=n)
            {
                sum2 = s2[r]+s1[l];
                cq2 = 1;
            }
            r--;
            x--;

            if(cq1 && cq2)
            {
                if(sum1>sum2)
                {
                    ans.pb(sum1);
                    l++;
                    y++;
                }
                else
                {
                    ans.pb(sum2);
                    r++;
                    x++;
                }
            }
            else if(cq1)
            {
                ans.pb(sum1);
                l++;
                y++;
            }
            else if(cq2)
            {
                ans.pb(sum2);
                r++;
                x++;
            }
            else
            {
                break;
            }
        }
        // cout<<x<<" "<<y;ce;
        rep(j,max(n,m)+1)
        {
            if(!(2*x+y<=m && 2*y+x<=n && y>=0 and x>=0))break;
            
            if(2*y+x >=m && 2*x+y >= n)
            {
                break;
            }
            else if(2*y+x ==n)
            {
                y--;
                x+=2;
                if(2*x+y<=m && 2*y+x<=n && y>=0 && x>=0)
                {
                    l--;
                    r+=2;
                    ans.pb(s1[l]+s2[r]);
                }
                else break;
            }
            else if(2*x+y == m)
            {
                x--;
                y+=2;
                if(2*x+y<=m && 2*y+x<=n && y>=0 && x>=0)
                {
                    r--;
                    l+=2;
                    ans.pb(s1[l]+s2[r]);
                }
                else break;
            }
        
        }
        cout<<ans.size();ce;
        out(ans);
    }

    return 0;
}

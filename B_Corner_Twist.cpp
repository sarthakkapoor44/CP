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
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<string> g1(n),g2(n);
        rep(i,n)cin>>g1[i]; 
        rep(i,n)cin>>g2[i]; 
        bool flag =1;
        rep(i,n)
        {
            if(!flag)break;
            rep(j,m)
            {
                if(g1[i][j]== g2[i][j])continue;
                else 
                {
                    ll a = ll(g1[i][j]-'0'),b = ll(g2[i][j]-'0');
                    if(((a+1)%3) == b)
                    {
                        if(j+1>= m || i+1>= n ){flag= 0;break;}
                        g1[i][j] = char(((a+1)%3)+'0');
                        g1[i+1][j+1] = char(((int)(g1[i+1][j+1]-'0')+1)%3 + '0');
                        g1[i+1][j] = char(((int)(g1[i+1][j]-'0')+2)%3 + '0');
                        g1[i][j+1] = char(((int)(g1[i][j+1]-'0')+2)%3 + '0');
                    }
                    else if(((a+2)%3)==b){
                        if(j+1>= m || i+1>= n ){flag= 0;break;}
                        g1[i][j] = char(((a+2)%3)+'0');
                        g1[i+1][j+1] = char(((int)(g1[i+1][j+1]-'0')+2)%3 + '0');
                        g1[i+1][j] = char(((int)(g1[i+1][j]-'0')+1)%3 + '0');
                        g1[i][j+1] = char(((int)(g1[i][j+1]-'0')+1)%3 + '0');
                    }
                    else flag =0;
                }
            }
        }
        // debug(g1);
        if(flag){pyes;}
        else pno;
        ce;
        
    }

    return 0;
}

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
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        string s;
        cin>>s;
        ll n =s.length();
        vector<string> fragments;
        bool ans = 1;
        function<bool(string)> is_pal= [&](string str)->bool
        {
            ll l = 0,r = str.length()-1;
            bool cq=1;
            while(l<=r)
            {
                if(str[l]!=str[r])
                {
                    cq=0;
                    break;
                }
                l++;r--;
            }
            return cq;
        };
        function<bool(ll,ll)>all_same= [&](ll l,ll r)->bool
        {
            for(int i=l;i<r;i++)
            {
                if(s[i+1]!=s[i])
                {
                    return false;
                }
            }
            return true;
        };
        if(all_same(0,n-1)){ans= 0 ;}
        else if(!is_pal(s))
        {
            fragments.pb(s);
        }
        else
        {
            
            char start = s[0];
            string part1 = "",part2= "";
            for(int i=0;i<n;i++)
            {
                if(s[i]==start)part1+= s[i];
                else 
                {
                    part1+= s[i];
                    // fragments.pb(part1);
                    ll temp = i;
                    i++;
                    while(i<n)
                    {
                        part2+=s[i];
                        i++;
                    }
                    // fragments.pb(part2);
                    if(is_pal(part2) || is_pal(part1))
                    {
                        part1+= part2[0];
                        reverse(all(part2));
                        part2.pop_back();
                        reverse(all(part2));
                        fragments.pb(part1);
                        fragments.pb(part2);
                    }
                    else
                    {
                        fragments.pb(part1);
                        fragments.pb(part2);
                        break;
                    }
                }
            }
            if(is_pal(part1) || is_pal(part2)){ans= 0;}
        }
        if(ans)
        {
            pyes;ce;
            cout<<fragments.size();ce;
            out(fragments);
        }
        else
        {
            pno;ce;
        }
        
    }

    return 0;
}

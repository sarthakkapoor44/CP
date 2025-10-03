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
#define pll pair<ll,ll>
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

    	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<string> answers = {"Enchanted","Truthful","Agamotto failed"};
        map<ll,vector<ll>> yes,no;
        vector<pair<char,ll>> arr;
        ll ycnt= 0,ncnt= 0;
        rep(i,n)
        {
            char sign;
            ll val;
            cin>>sign>>val;
            arr.pb({sign,val});
            if(sign == '+')
            {
                yes[val].pb(i+1);
                ycnt++;
            }
            else
            {
                no[val].pb(i+1);
                ncnt++;
            }
        }
        // set<ll> truthful,enchanted,agamotto;
        vll vals(n+1,INF);
        ll times =0;
        for(int i=1;i<=n;i++)
        {
            ll lie = 0,truth = 0;
            truth+= yes[i].size();
            lie+= no[i].size();
            truth+= ncnt-no[i].size();
            lie+= ycnt-yes[i].size();
            if(!times)
            {
                vll t,f;
                if(truth == m)
                {   
                    for(auto x:yes[i])
                    {
                        if(vals[x]==INF || vals[x]==1)vals[x]=1;
                        else vals[x]=-1;
                        t.pb(x);
                    }
                    for(auto x:no[i])
                    {
                        if(vals[x]==INF || vals[x]==0)vals[x]=0;
                        else vals[x]=-1;
                        f.pb(x);
                    }
                    for(auto x:no)
                    {
                        if(x.fi!=i)
                        {
                            for(auto y:x.se)
                            {
                                if(vals[y]==INF || vals[y]==1)vals[y]=1;
                                else vals[y]=-1;
                                t.pb(y);
                            }
                        }
                    }
                    
                    for(auto x:yes)
                    {
                        if(x.fi!=i)
                        {
                            for(auto y:x.se)
                            {
                                if(vals[y]==INF || vals[y]==0)vals[y]=0;
                                else vals[y]=-1;
                                f.pb(y);
                            }
                        }
                    }
                    // debug(i,t,f,vals);
                }
           
            }
        }
            for(int i =1;i<=n;i++)
            {
                if(vals[i]==0)cout<<answers[0]<<endl;
                else if(vals[i]==1)cout<<answers[1]<<endl;
                else cout<<answers[2]<<endl;
            }
        
    

    return 0;
}

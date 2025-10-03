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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll divs;
        ll cnt2=0;
        ll curr=n;
        for(ll i=2;i*i<=n;i++)
        {
            if(curr%i==0)
            {
                ll c=0;
                while(curr%i==0)
                {
                    c++;
                    curr/=i;
                }
                divs.pb(i);
            }
        }
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt2++;
                if(i*i!=n)
                {
                    cnt2++;
                }
            }
        }
        if(cnt2%2==1)
        {
            cout<<"N"<<endl;
            return 0;
        }
        priority_queue<ll>pq;
        if(curr>1)
        {
            divs.pb(1);
        }
        ll val=1;
        for(auto &x:divs)
        {
            pq.push(x);
            val*=(x+1);
        }
        val-=1;
        ll c=1;
        if(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            val+=1;
            val/=node;
            val*=node-1;
            val--;
        }
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            if(val>0)
            {
                c++;
                val+=1;
                val/=node;
                val*=node-1;
                val-=1;
                if(!pq.empty())
                {
                    auto node=pq.top();
                    pq.pop();
                    val+=1;
                    val/=node;
                    val*=node-1;
                    val-=1;
                }
            }
            else
            {
                break;
            }
        }
        if(c>=cnt2/2)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }
        
    }

    return 0;
}

///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag,
   tree_order_statistics_node_update> ost;
 
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
        ll n,q;
        cin>>n>>q;
        vll arr(n);
        rep(i,n)cin>>arr[i] ;
        string s;cin>>s;
        ost done;
        vll move(n);
        forb(i,n-1,0)
        {
            done.insert(arr[i]);

            ll val = max(0ll,ll(done.order_of_key(arr[i]) +(i+1) -arr[i]));
            move[i] = val;
        }
        // out(move);

        vll temp(n);

        rep(i,n)if(s[i]=='R')temp[i+1]++;
        else temp[i]++;

        ll val =0;
        ll cnt= 0;
        // rep(i,n)
        // {
        //     if(temp[i])val++;
        //     else 
        //     {
        //         val= 0 ; 
        //     }
        //     if(move[i]>val){cnt++;}
        // }

        vll dep(n);
        rep(i,n)
        {
            if(move[i])
            {
                dep[i]+=1;
                dep[i-move[i]]+=-1;
            }
        }
        ll sum =0 ;
        forb(i,n-1,0)
        {
            sum+= dep[i];
            dep[i]=min(sum,1ll);
        }
        rep(i,n)
        {
            if(dep[i] && !temp[i])cnt++;
        }
        rep(i,q)
        {
            ll idx;
            ll cq= 0;
       
            cin>>idx;
            idx--;
            if(s[idx]=='L')
            {
                temp[idx]--;
                if(!temp[idx] && dep[idx]){cnt++;}
                if((!temp[idx+1]) && dep[idx+1])cnt--;
                temp[idx+1]++;
                s[idx] ='R';
            }
            else
            {
                temp[idx+1]--;
                if(!temp[idx+1] && dep[idx+1]){cnt++;}
                if(!temp[idx] && dep[idx])cnt--;
                temp[idx]++;
                s[idx]='L';
            }

            if(cnt==0)cq=1;     

            if(cq)pyes;
            else pno;

            ce;
        }
        // debug(dep);
    }

    return 0;
}

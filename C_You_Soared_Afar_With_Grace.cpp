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
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr1(n),arr2(n); 
        rep(i,n)cin>>arr1[i];
        rep(i,n)cin>>arr2[i];
        ll s  = 0;
        vector<ll> idx1(n+1),idx2(n+1);
        rep(i,n)
        {
            idx2[arr2[i]] = i+1;
            idx1[arr1[i]] = i+1;
        }
        rep(i,n)
        {
            if(arr1[i]==arr2[i])
            {
                s++;
            }
        }
        ll cq= 1;
        vp moves;
        if( s>1 || (s==1 and n%2==0) || (s!=1 and n%2==1))cq=0;
        else
        {
            ll l = 0,r = n-1;
            while(l<=r)
            {
                if(arr1[l]!=arr2[r])
                {
                    ll index = idx2[arr1[l]]-1;
                    if(index <=l || index >r )
                    {
                        index = idx1[arr2[r]]-1;
                        if(index >= r || index <l)
                        {
                            cq=0;
                            break;
                        }
                        else
                        {
                            swap(arr1[l],arr1[index]);
                            swap(arr2[l],arr2[index]);
                            moves.pb({l+1,index+1});
                            idx1[arr1[l]] = l+1;
                            idx1[arr1[index]] = index+1;
                            idx2[arr2[l]] = l+1;
                            idx2[arr2[index]] = index+1;
                        }
                    }
                    else 
                    {
                        swap(arr2[r],arr2[index]);
                        swap(arr1[r],arr1[index]);
                        moves.pb({r+1,index+1});
                        idx2[arr2[r]] = r+1;
                        idx2[arr2[index]] = index+1;
                        idx1[arr1[r]] = r+1;
                        idx1[arr1[index]] = index+1;
                    }  
                }
                // debug(l,r,moves,idx1,idx2);
                l++;
                r--;
                if(!cq)break;
            }
        }
        ll l =0 ,r = n-1;
        while(l<n-1)if(arr1[l]!=arr2[r]){cq=0;break;}else{l++;r--;}
        if(cq)
        { 
            cout<<moves.size()<<endl;
            if(moves.size())for(auto x:moves){cout<<x.fi<<" "<<x.se;ce;}  
        }
        else {cout<<-1;ce;}
    }

    return 0;
}

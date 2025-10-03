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
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        map<ll,vll> nums;
        rep(i,n)
        {
            cin>>arr[i];
            nums[(arr[i]%k)].push_back((arr[i]/k));
        }
        ll odd = 0;
        ll ans = 0;
        for(auto x:nums)
        {
            vector<ll> temp = x.se;
            odd+= (temp.size()%2);
            srt(temp);
            if((temp.size()%2))
            {
                vll arr_new =  temp;
                for(int i=0;i<temp.size();i+=2)
                {
                    arr_new[i]*=-1;
                }
                vll pre(temp.size()),suff(temp.size());
                rep(i,temp.size())
                {
                    pre[i] = (i?pre[i-1]:0)+ arr_new[i];
                }
                forb(i,temp.size()-1,0)
                {
                    suff[i] = ((i+1<temp.size())?suff[i+1]:0) + (-arr_new[i]);
                }
                ll  min_val =INF;
                for(int i=0;i<temp.size();i+=2)
                {
                    ll val = (i?pre[i-1]:0) + ((i+1<temp.size())?suff[i+1]:0);
                    min_val = min(min_val,val);
                }
                ans+= min_val;
            }
            else{
                rep(i,temp.size())
                {
                    if(!(i%2))ans+= (-temp[i]);
                    else ans+= temp[i];
                }
            }
        }
        if(odd>1){
            ans=-1;
        }
        cout<<ans;ce;
        
    }

    return 0;
}

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

struct node {
    node* links[2] = {NULL,NULL};
};
class Trie{
    private: node* root  =  new node();
    public:
        void insert(ll num)
        {
            node* temp =  root;
            for(int i=31;i>=0;i--)
            {
                int val = ((1ll<<i)&num)?1:0;
                if(!temp->links[val])temp->links[val] = new node();
                temp = temp->links[val];
            }
        }
        ll max_val(ll num)
        {
            node* temp =  root;
            ll ans = 0;
            for(int i=31;i>=0;i--)
            {
                ll val = ((1ll<<i)&num)?1:0;
                if(temp->links[(val^1)]){ val^=1; ans += (1ll<<i);}
                temp = temp->links[val];
            }
            return ans;
        }
};
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr;
        arr.push_back(0);
        rep(i,n-1)
        {
            ll num;cin>>num;
            arr.push_back(arr.back()^num);
        }
        // out(arr);
        Trie obj;
        for(auto x:arr)obj.insert(x);

        rep(i,n)
        {
            // cout<<obj.max_val(i)<<" ";
            if(obj.max_val(i) == n-1)
            {
                rep(j,n)arr[j]^= i;
                break;
            }
        }
        // ce;
        out(arr);
        
    }

    return 0;
}

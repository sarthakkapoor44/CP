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
struct TrieNode {
    TrieNode* children[2];
    int max_idx;
    bool isEnd = false;
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        max_idx = -1;

    }
};
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
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        rep(i,n)cin>>arr[i]; 
        if(k==0)
        {
            cout<<1<<endl;
            continue;
        }
        ll ans =INF;
        bitset<32> kk(k);
        TrieNode* root = new TrieNode();
        rep(i,n)
        {
            bitset<32> bits(arr[i]);
            TrieNode* node = root;
            bool cq=1;
            for(int j =31;j>=0;j--)
            {
                if(kk[j]==0)
                {
                    if(node->children[1-bits[j]]!=nullptr)
                    {
                        // node = node->children[1-bits[j]];
                        ans = min(ans,i-(node->children[1-bits[j]]->max_idx)+1);
                    }
                    
                    node = node->children[bits[j]];
                    if(node==nullptr)
                    {
                        cq=0;
                        break;
                    }
                    else if(node->isEnd)
                    {
                        ans = min(ans,i-node->max_idx+1);
                        break;
                    }
                
                }
                else 
                {
                    node = node->children[1-bits[j]];
                    if(node ==nullptr){cq= 0;break;}
                    else if(node->isEnd)
                    {
                        ans = min(ans,i-node->max_idx+1);
                        break;
                    }   
                }
            }
            node= root;
            for (int j = 31; j >= 0; j--) {
                int bit = bits[j];
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
                node->max_idx = i;
            }
            node->isEnd = true;
        }
        cout<<((ans==INF)?-1:ans);ce;
    }

    return 0;
}

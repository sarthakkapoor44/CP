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


template <typename T>
class SegmentTree {
private:
    int n;                            // Size of the input array
    std::vector<T> tree;              // Segment tree array
    std::function<T(T, T)> function;  // Function to combine two nodes (e.g., sum, min, max)
    T default_value;                  // Default value for non-overlapping segments

    // Build the segment tree
    void build(const std::vector<T>& data, int node, int start, int end) {
        if (start == end) {
            // Leaf node: store the data value
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);        // Build left child
            build(data, 2 * node + 2, mid + 1, end);      // Build right child
            tree[node] = function(tree[2 * node + 1], tree[2 * node + 2]); // Combine child results
        }
    }

    // Update a value in the segment tree
    void update(int node, int start, int end, int idx, T value) {
        if (start == end) {
            // Leaf node: update the data value
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                // Update left child
                update(2 * node + 1, start, mid, idx, value);
            } else {
                // Update right child
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            // After update, combine the results of both children
            tree[node] = function(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Query the segment tree for range [L, R]
    T range_query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            // If the range [L, R] is completely outside the segment [start, end]
            return default_value;
        }
        if (L <= start && end <= R) {
            // If the segment [start, end] is completely inside the range [L, R]
            return tree[node];
        }

        // If the segment [start, end] overlaps with the range [L, R]
        int mid = (start + end) / 2;
        T left_query = range_query(2 * node + 1, start, mid, L, R);
        T right_query = range_query(2 * node + 2, mid + 1, end, L, R);
        return function(left_query, right_query);
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const std::vector<T>& data, std::function<T(T, T)> func, T default_val)
        : function(func), default_value(default_val) {
        n = data.size();
        tree.resize(4 * n, default_val);
        build(data, 0, 0, n - 1);
    }

    // Public method to update a value
    void update(int idx, T value) {
        update(0, 0, n - 1, idx, value);
    }

    // Public method to query a range [L, R]
    T range_query(int L, int R) {
        return range_query(0, 0, n - 1, L, R);
    }

    // Public method to display the segment tree (for debugging)
    void print() const {
        for (const auto& val : tree) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr(n);
        map<ll,vector<ll>> freq;
        rep(i,n){cin>>arr[i];freq[arr[i]].pb(i);}
        SegmentTree<ll> seg(arr,[](ll a,ll b){return __gcd(a,b);},0);
        ll q;cin>>q;
        rep(i,q)
        {
            ll l,r;cin>>l>>r;
            l--;r--;
            ll val = seg.range_query(l,r);
            ll sub = 0;
            if(freq[val].size())
            {
                ll idx1 = lower_bound(freq[val].begin(),freq[val].end(),l) - freq[val].begin();
                ll idx2 = lower_bound(freq[val].begin(),freq[val].end(),r) - freq[val].begin();
                if(idx2  == freq[val].size())idx2--;
                if(freq[val][idx2]>r)idx2--;
                sub = idx2 -  idx1 + 1;
            }
            cout<<(r-l+1)-sub<<'\n';
        }
        
    }

    return 0;
}


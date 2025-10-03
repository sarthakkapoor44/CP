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
 

template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
static const long long MOD = 998244353;
static const int MAXN = 400005;

long long pow2Arr[MAXN+1], inv2Arr[MAXN+1];

long long modexp(long long base, long long exp, long long m) {
    long long result = 1 % m; 
    base %= m;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

void precomputePow2(int n) {
    pow2Arr[0] = 1;
    for(int i = 1; i <= n; i++) pow2Arr[i] = (pow2Arr[i-1] * 2) % MOD;
    for(int i = 0; i <= n; i++) inv2Arr[i] = modexp(pow2Arr[i], MOD-2, MOD);
}

struct Agg {
    int size;
    long long sum_inv, sum_pow, F1, F2, first, last;
};

Agg idd() {
    return {0,0,0,0,0,0,0};
}

Agg combineAgg(const Agg &A, const Agg &B) {
    if(!A.size) return B;
    if(!B.size) return A;
    Agg ret;
    ret.size = A.size + B.size;
    ret.sum_inv = (A.sum_inv + (B.sum_inv * inv2Arr[A.size]) % MOD) % MOD;
    ret.sum_pow = (A.sum_pow + (B.sum_pow * pow2Arr[A.size]) % MOD) % MOD;
    long long cross = ( (pow2Arr[A.size] * A.sum_inv) % MOD * B.sum_pow ) % MOD;
    ret.F1 = (A.F1 + B.F1 + cross) % MOD;
    ret.F2 = (A.F2 + B.F2 + (A.last * B.first) % MOD) % MOD;
    ret.first = A.first;
    ret.last = B.last;
    return ret;
}

struct Node {
    long long val;
    int id, priority, size;
    Agg agg;
    Node *left, *right;
};

int getSize(Node* t) { return t ? t->size : 0; }

inline Agg singleAgg(long long val) {
    Agg a = {1, 0, 0, 0, 0, 0, 0};
    a.sum_inv = (val % MOD) * inv2Arr[1] % MOD;
    a.sum_pow = val % MOD;
    a.first = a.last = val % MOD;
    return a;
}

void updateNode(Node* t) {
    if(!t) return;
    t->size = 1 + getSize(t->left) + getSize(t->right);
    Agg merged = idd();
    if(t->left) merged = combineAgg(merged, t->left->agg);
    merged = combineAgg(merged, singleAgg(t->val));
    if(t->right) merged = combineAgg(merged, t->right->agg);
    t->agg = merged;
}

Node* newNode(long long val, int id) {
    Node* n = new Node();
    n->val = val;
    n->id = id;
    n->priority = rand();
    n->left = n->right = nullptr;
    n->agg = singleAgg(val);
    n->size = 1;
    return n;
}

void split_by_key(Node* t, long long val, int id, Node*& L, Node*& R) {
    if(!t) { L = R = nullptr; return; }
    if(t->val < val || (t->val == val && t->id < id)) {
        split_by_key(t->right, val, id, t->right, R);
        L = t; updateNode(L);
    } else {
        split_by_key(t->left, val, id, L, t->left);
        R = t; updateNode(R);
    }
}

Node* merge_treap(Node* L, Node* R) {
    if(!L || !R) return L ? L : R;
    if(L->priority > R->priority) {
        L->right = merge_treap(L->right, R);
        updateNode(L);
        return L;
    } else {
        R->left = merge_treap(L, R->left);
        updateNode(R);
        return R;
    }
}

void treap_insert(Node*& t, Node* item) {
    if(!t) { t = item; return; }
    if(item->priority > t->priority) {
        split_by_key(t, item->val, item->id, item->left, item->right);
        t = item;
    } else if(item->val < t->val || (item->val == t->val && item->id < t->id)) {
        treap_insert(t->left, item);
    } else {
        treap_insert(t->right, item);
    }
    updateNode(t);
}

void treap_erase(Node*& t, long long val, int id) {
    if(!t) return;
    if(t->val == val && t->id == id) {
        Node* tmp = merge_treap(t->left, t->right);
        delete t; t = tmp;
    } else if(val < t->val || (val == t->val && id < t->id)) {
        treap_erase(t->left, val, id);
    } else {
        treap_erase(t->right, val, id);
    }
    if(t) updateNode(t);
}

Node* root = nullptr;
long long getF() {
    return root ? (root->agg.F1 + root->agg.F2) % MOD : 0;
}


int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    int T; cin >> T; 
    precomputePow2(MAXN);
    while(T--) {
        int N, Q; 
        cin >> N >> Q;
        vector<int> A(N+1);
        for(int i = 1; i <= N; i++) cin >> A[i];
        root = nullptr;
        for(int i = 1; i <= N; i++) treap_insert(root, newNode(A[i], i));
        cout << getF() << "\n";
        while(Q--) {
            int x, v; 
            cin >> x >> v;
            treap_erase(root, A[x], x);
            A[x] = v;
            treap_insert(root, newNode(v, x));
            cout << getF() << "\n";
        }
        function<void(Node*)> freeTree = [&](Node* t) {
            if(!t) return;
            freeTree(t->left); freeTree(t->right); delete t;
        };
        freeTree(root);
        root = nullptr;
    }
    return 0;
}



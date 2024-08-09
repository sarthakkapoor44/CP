///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to insert nodes in level order
TreeNode* insertLevelOrder(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    std::queue<TreeNode*> q;
    TreeNode* root = new TreeNode(values[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}
void printLevelOrder(TreeNode* root) {
    if (!root) {
        std::cout << "The tree is empty." << std::endl;
        return;
    }

    std::queue<TreeNode*> nodesQueue;
    int level = 0;
    nodesQueue.push(root);
    nodesQueue.push(nullptr); // Marker for end of a level

    while (!nodesQueue.empty()) {
        TreeNode* current = nodesQueue.front();
        nodesQueue.pop();

        if (current == nullptr) {
            std::cout << std::endl; // End of a level
            if (!nodesQueue.empty()) {
                nodesQueue.push(nullptr); // Adding marker for next level
            }
            level++;
        } else {
            std::cout << current->val << " ";
            if (current->left != nullptr) {
                nodesQueue.push(current->left);
            }
            if (current->right != nullptr) {
                nodesQueue.push(current->right);
            }
        }
    }
}
int lastNode(TreeNode* A) {
    int val=0,mr=INT_MIN,mc=INT_MIN;
    function<void(TreeNode*,int,int)> dfs =[&](TreeNode* root,int r ,int c)->void
    {
        if(root==NULL)return;
        if(mr<=r)
        {
            if(mr==r)
            {
                if(mc<=c){mc=c;val =root->val;}
            }
            else {mc=c;mr=r;val= root->val;}
        }
        cout<<root->val<<" "<<r<<" "<<c;ce;
        dfs(root->left,r+1,c-1);
        dfs(root->right,r+1,c+1);
    };
    dfs(A,0,0);
    return val;
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<int> nodes(n);
        rep(i,n)cin>>nodes[i];
        TreeNode* root = insertLevelOrder(nodes);
        printLevelOrder(root);
        int val  =lastNode(root);
        cout<<val;
    }

    return 0;
}

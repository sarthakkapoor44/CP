///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
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
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
struct TrieNode {

    // pointer array for child nodes of each node
    TrieNode* childNode[26];
    int arr[26];
    // Used for indicating ending of string
    bool wordEnd;

    TrieNode()
    {
        // constructor
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with
        // NULL
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void insert_key(TrieNode* root, string& key)
{
    // Initialize the currentNode pointer
    // with the root node
    TrieNode* currentNode = root;

    // Iterate across the length of the string
    for (auto c : key) {

        // Check if the node exist for the current
        // character in the Trie.
        if (currentNode->childNode[c - 'a'] == NULL) {

            // If node for current character does not exist
            // then make a new node
            TrieNode* newNode = new TrieNode();
            for(int i=0;i<26;i++)newNode->arr[i]=0;
            // Keep the reference for the newly created
            // node.
            currentNode->childNode[c - 'a'] = newNode;
           
        }

        // Now, move the current node pointer to the newly
        // created node.
        currentNode->arr[c-'a']++;
        currentNode = currentNode->childNode[c - 'a'];
    }

    // Increment the wordEndCount for the last currentNode
    // pointer this implies that there is a string ending at
    // currentNode.
    currentNode->wordEnd = 1;
}
void find_sum(TrieNode* root, string& key,ll &temp,int order)
{
    TrieNode* currentNode = root;
  
    for(auto c:key)
    {
        temp+=currentNode->arr[c-'a']-1;
        currentNode = currentNode->childNode[c - 'a'];
    }

}


int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        TrieNode *root = new TrieNode();
        rep(i,26)root->arr[i]=0;
        vector<string> strings;
        rep(i,n)
        {
            string s;cin>>s;
            strings.pb(s);
            insert_key(root,s);
        }
        // for(auto x:root->arr)cout<<x<<" ";ce;
        ll sum =0;
        rep(i,n)
        {
            ll temp = 0;
            find_sum(root,strings[i],temp,n-1);
            sum+=temp;
            // cout<<temp;ce;
        }
        cout<<sum/2;ce;
        
        
    }

    return 0;
}

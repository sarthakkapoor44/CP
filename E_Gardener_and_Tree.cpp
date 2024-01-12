#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
const ll MODN= 1e9 + 7;
/*ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}*/
void print(unordered_map<ll,set<ll> > &adj,ll n){
forf(i,1,n+1){
    cout<<i<<"-> ";for(auto x:adj[i]){cout<<x<<" ";}ce;
}
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        unordered_map<ll,set<ll> > adj;
        if(n!=1){
        rep(i,n-1){
            ll a,b;
            cin>>a>>b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        queue<ll> remove;
        v visited(n+1,0);
        forf(i,1,n+1){if(adj[i].size()==1){remove.push(i);visited[i]=1;}}
        // cout<<remove.size()<<" ";
        ll vals_rem = 0;
        // print(adj,n);ce;
        while(k-- && !remove.empty()){
            ll total = remove.size();
           while(total--){
            ll val = remove.front();
            //  cout<<val;ce;
            remove.pop();vals_rem++;
            if(adj[val].size()>0){
            ll num = *(--adj[val].end());
            for(auto x:adj[val]){adj[x].erase(val);}
            adj[val].clear();
            if(!visited[num] && num>=1 && num<=n && adj[num].size()==1){remove.push(num);visited[num]=1;}
        //  print(adj,n);ce;
            // cout<<num<<" ";
            }
            }
        
        }
        // cout<<vals_rem;ce;
       cout<<n-vals_rem;ce;}else{cout<<0;ce;}
    }
return 0;
}
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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n,0);
        map<ll,v> adj;
        ll cq=1;
        v indices;
        v pos;
        rep(i,n)
        {
            ll t,val;
            cin>>t>>val;
            if(t==1){
                adj[val].pb(i);
                indices.pb(i);
                pos.pb(1);
            }
            else{
                pos.pb(2);
                if(!adj[val].size())cq=0;
                else {
                    arr[*(--adj[val].end())]=1;
                   adj[val].pop_back();
                }
            }
        }
        
        v arr2;
        rep(i,indices.size()){arr2.pb(arr[indices[i]]);}
        ll mx =-INF;
        ll curr=0;
        rep(i,n){
            if(pos[i]==1){if(arr[i])curr++;}
            else if(pos[i]==2){
                mx  = max(mx,curr);
                curr--;
            }
        }

       if(cq){cout<<max(0ll,mx); ce;rep(i,indices.size())cout<<arr2[i]<<" ";}
       else cout<<-1;
        ce;
        
    }

    return 0;
}

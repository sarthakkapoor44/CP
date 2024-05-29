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
        ll arr[n];
        rep(i,n)cin>>arr[i];
        ll q;cin>>q;
        map<ll,ll> fwd,bwd;
        fwd[-1]=arr[0];
        bwd[arr[0]]=-1;
        forf(i,1,n){
            fwd[arr[i-1]]=arr[i];
        }
        fwd[arr[n-1]]=-2;
        forb(i,n-1,1){
            bwd[arr[i]]=arr[i-1];
        }
        bwd[-2]=arr[n-1];
        // ll head  = arr[0];
        rep(i,q){
            ll type;cin>>type;
            if(type==1){
                ll a,b;cin>>a>>b;
                ll next = fwd[a];
                fwd[a] =b;
                fwd[b] =next;
                bwd[b]=a;
                bwd[next]=b;
            }
            else {
                ll a;cin>>a;
                ll prev = bwd[a];
                fwd[prev] = fwd[a];
                bwd[fwd[a]] = prev;
                fwd.erase(a);
                bwd.erase(a);
               
            }
        }
        ll start=-1;
        while(fwd[start]!=-2){cout<<fwd[start]<<" ";start=fwd[start];}ce;
        
    }

    return 0;
}

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
#define pyes cout<<"Yes";
#define pno cout<<"No";
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
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    {   //Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        string s;cin>>s;
        set<ll> pos;
        rep(i,n-1)if(s[i+1]==s[i])pos.insert(i);
        pos.insert(n);
        // for(auto x:pos)cout<<x<<" ";ce;
        rep(i,q)
        {
            ll type,l,r;cin>>type>>l>>r;
            l--;r--;
            if(type==2)
            {
                auto a = pos.lower_bound(l);
                auto b = pos.lower_bound(r);
                if(a==b){pyes;}
                else{pno;}
                ce;
            }
            else 
            { 
                    ll lpv;
                    ll lv = s[l]-'0';
                    ll rv = s[r]-'0';
                    if(l-1>=0)
                    {
                        lpv  = s[l-1]-'0';
                        if((1-lv)==lpv)pos.insert(l-1);
                        else pos.erase(l-1);
                    }
                    if(r+1<n)
                    {
                       ll rnv= s[r+1]-'0';
                       if((1-rv)==rnv)pos.insert(r);
                       else pos.erase(r);
                    }
                
            }
          
        }
        
    }

    return 0;
}
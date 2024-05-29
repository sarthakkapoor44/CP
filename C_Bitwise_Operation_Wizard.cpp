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
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll mx_idx=0;
        forf(i,1,n)
        {
            cout<<"? "<<i<<" "<<i<<" "<<mx_idx<<" "<<mx_idx;ce;
            cout.flush();
            char val;
            cin>>val;
            if(val=='>'){mx_idx=i;}
        }
        vector<ll> mx_xors;
        ll temp=0;
        mx_xors.pb(0);
        forf(i,1,n)
        {

            cout<<"? "<<i<<" "<<mx_idx<<" "<<temp<<" "<<mx_idx;
            cout.flush();
            ce;
            char val;
            cin>>val;
            if(val=='>'){temp=i;mx_xors.clear();mx_xors.pb(i);}
            else if(val=='='){mx_xors.pb(i);}
        }
        // for(auto x:mx_xors){cout<<x<<" ";}ce;
        ll min_idx=mx_xors[0];
        forf(i,1,mx_xors.size())
        {
            cout<<"? "<<mx_xors[i]<<" "<<mx_xors[i]<<" "<<min_idx<<" "<<min_idx;
            cout.flush();
            ce;
            char val;
            cin>>val;
            if(val=='<'){min_idx=mx_xors[i];}
        }
        cout<<"! "<<mx_idx<<" "<<min_idx;
        cout.flush();
        ce;

    }

    return 0;
}

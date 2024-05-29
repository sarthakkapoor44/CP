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
        string s;
        cin>>s;
        ll ru = 0,rr = 0,iu= 0,ir =0; 
        vector<char> moves;
        ll r_moves=0,i_moves=0;

        rep(i,n)
        {
            if(s[i]=='N')
            {
                if(ru<iu){ru++;moves.pb('R');r_moves++;}
                else if(iu<ru){iu++;moves.pb('H');i_moves++;}
                else 
                {
                    if(r_moves>i_moves){iu++;moves.pb('H');i_moves++;}
                    else{ru++;moves.pb('R');r_moves++;}
                }
                
            }
            else if(s[i]=='S')
            {
                if(ru>iu){ru--;moves.pb('R');r_moves++;}
                else if(ru<iu) {iu--;moves.pb('H');i_moves++;}
                else 
                {
                    if(r_moves>i_moves){iu--;moves.pb('H');i_moves++;}
                    else{ru--;moves.pb('R');r_moves++;}
                }
            }
            else if(s[i]=='E')
            {
                if(rr<ir){rr++;moves.pb('R');r_moves++;}
                else if(rr>ir){ir++;moves.pb('H');i_moves++;}
                else 
                {
                    if(r_moves>i_moves){ir++;moves.pb('H');i_moves++;}
                    else{rr++;moves.pb('R');r_moves++;}
                }
            }
            else if(s[i]=='W')
            {
                if(rr>ir){rr--;moves.pb('R');r_moves++;}
                else if(rr<ir) {ir--;moves.pb('H');i_moves++;}
                else 
                {
                    if(r_moves>i_moves){ir--;moves.pb('H');i_moves++;}
                    else{rr--;moves.pb('R');r_moves++;}
                }
            }
        }

        if(ru== iu && rr == ir && r_moves && i_moves)
        {
            for(auto x:moves)cout<<x;
        }
        else {pno;}
        ce;
    }

    return 0;
}

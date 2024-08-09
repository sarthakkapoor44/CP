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
        v arr1(n),arr2(n+1);
        rep(i,n)cin>>arr1[i];
        rep(i,n+1)cin>>arr2[i];
        ll moves =0;
        bool flag=0;
        rep(i,n)
        {
            moves+= max(arr1[i],arr2[i]) -min(arr1[i],arr2[i]);
            if(arr2[n] <= max(arr1[i],arr2[i]) && arr2[n] >= min(arr1[i],arr2[i]) )flag=1;
        }
        if(flag)moves++;
        else 
        {
            moves++;
            ll temp=INF;
            rep(i,n)
            {
                if(arr2[n]>max(arr1[i],arr2[i])){temp =min(temp,arr2[n]-max(arr1[i],arr2[i]));}
                else temp =min(temp,min(arr1[i],arr2[i])-arr2[n]);
            
            }
            moves+=temp;
        }
        cout<<moves;ce;
    }

    return 0;
}

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
        ll n,q;
        cin>>n>>q;
        v arr(n);
        rep(i,n)cin>>arr[i];
        ll last_inserted_min=-INF;
        ll min_to_insert=arr[0];
        v sum((n+1)/2);
        sum[0]=arr[0];
        for(int i=1;2*i+1<=n;i++)
        {
            ll a = arr[2*i-1];
            ll b= arr[2*i];
            if(a>b)swap(a,b);
            if(last_inserted_min>a)
            {
                if(last_inserted_min>b)
                {
                    sum[i] = sum[i-1]+2*last_inserted_min -a-b;
                    last_inserted_min = b;
                    min_to_insert= last_inserted_min;
                }
                else 
                {
                    sum[i] =  sum[i-1]+b-a;
                    min_to_insert= min(min_to_insert,b);
                }
            }
            else 
            {
                if(min_to_insert>a)
                {
                    sum[i] = sum[i-1]-a+b;
                    last_inserted_min = a;
                    min_to_insert = min(min_to_insert,b);
                }
                else
                {
                    sum[i] = sum[i-1]-2*min_to_insert+a+b;
                    last_inserted_min = min_to_insert;
                    min_to_insert=a;
                }
            }
        }
        for(auto x: sum)cout<<x<<" ";
        rep(i,q)
        {
            ll query;cin>>query;
            // cout<<sum[(query-1)/2]<<" ";

        }
         
        
    }

    return 0;
}

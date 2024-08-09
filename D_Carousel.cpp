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
        v arr(n);
        rep(i,n)cin>>arr[i];
        bool cq=0;
        ll cnt  =0;
        rep(i,n)
        {
            if(arr[(i+1)%n]==arr[i]){cq=1;}
            else cnt++;
        } 
        v ans(n);
        ans[0]=0;
        {
            rep(i,n-1)
            {
                if(arr[i+1]!=arr[i]){ans[i+1]=1-ans[i];}
                else ans[i+1]=ans[i];
            }
        }
        ll sizes =2;
        if(!cq && ans[n-1]==ans[0])
        {
            
            ans[n-1]=2;
            sizes=3;
        }
        else if(cq && ans[n-1]==ans[0] && arr[n-1]!=arr[0])
        {
          
            ll idx=0;
            forb(i,n-2,0)
            {
                if(arr[i+1]==arr[i]){idx=i;break;}
            }
            ans[idx+1] =1-ans[idx];
            forf(i,idx+1,n-1)
            {
                if(arr[i+1]!=arr[i]){ans[i+1]=1-ans[i];}
                else ans[i+1]=ans[i];
            }
        }
        if(!cnt)sizes=1;
        cout<<sizes;ce;
        rep(i,n)cout<<ans[i]+1<<" ";ce;
    }

    return 0;
}

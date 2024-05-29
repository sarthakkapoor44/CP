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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   
        //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n);
        ll sum=0;
        rep(i,n){cin>>arr[i];sum+=arr[i];}
        ll mx_val =-INF;
        ll valf =0,valr=0;
        ll cum_sum =0;
        rep(i,n-1)
        {
            cum_sum+=arr[i];
            valf+=cum_sum;
        }
        valr = (n-1)*sum-valf;
        rep(i,n)
        {
            mx_val=max(valf,mx_val);
            mx_val = max(valr,mx_val);
            valf = valf - (n)*arr[i] + sum;
            valr = (n-1)*sum-valf;
            
        }
        cout<<mx_val;ce;
    }

    return 0;
}

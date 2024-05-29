// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fi first
// #define se second
// #define mp make_pair

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     ll n;
//     cin >> n;
//     vector<pair<ll, int> > events;  // Store events
//     events.reserve(2 * n);

//     for (ll i = 0; i < n; ++i) {
//         ll l, r;
//         cin >> l >> r;
//         events.emplace_back(l, 1);   // Start of interval
//         events.emplace_back(r + 1, -1); // End of interval, +1 to handle inclusive
//     }

//     // Sort events, first by time, then by type (end before start if same time)
//     sort(events.begin(), events.end());

//     ll active = 0, ans = 0;
//     for (auto& event : events) {
//         if (event.se == 1) { // Start of an interval
//             ans += active;  // Count all active intervals that this one intersects with
//             active++;
//         } else { // End of an interval
//             active--;
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }

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
bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(b.first>a.first)return 1;
    else if(b.first== a.first && a.second>b.second)return 1;
    return 0;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vp arr;
        set<ll> curr;
        rep(i,n){
            ll a,b;cin >>a>>b;
            arr.push_back(mp(a,i+1));
            arr.push_back(mp(b,-(i+1)));
        } 
        sort(arr.begin(),arr.end(),compare);
        ll ans  =0;
        rep(i,arr.size())
        {
            if(arr[i].se<0)
            {
                curr.erase(-arr[i].se);
            }
            else 
            {
                ans+=curr.size();
                curr.insert(arr[i].se);
            }
        }
        cout<<ans;ce;
    }

    return 0;
}
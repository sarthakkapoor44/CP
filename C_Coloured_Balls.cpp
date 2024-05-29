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
        ll n,k;
        cin>>n>>k;
        vp arr(n,mp(0,0));
        
        rep(i,n)cin>>arr[i].fi;// ai
        rep(i,n){cin>>arr[i].se;}
        srt(arr);


        ll prev = 0;
        map<ll,ll> freq;
        map<pair<ll,ll> ,ll> freq2;
        rep(i,n)
        {
            freq2[arr[i]]++;
        }
        rep(i,n)
        {
           freq[arr[i].fi]++;
           while(i+1<n && arr[i+1].fi==arr[i].fi) {freq[arr[i].fi]++;i++;}
           freq[arr[i].fi]+=prev;
           prev = freq[arr[i].fi];
        }


        vector<vector<ll> > colors(n);
        rep(i,n)colors[arr[i].se-1].pb(i);
    //    cout<<colors.size();ce;
        vp freq3;
        rep(i,colors.size()){
            if(colors[i].size())freq3.pb(mp(colors[i].size(),colors[i][0]));}
        sort(all(freq3),greater<pair<ll,ll> >());
        
        ll ans =INF;
        for(auto x:freq3)
        {
            if(freq[arr[x.se].fi]-freq2[arr[x.se]]<=k){ans =max(0ll,n-x.fi-k);break;}
        }
        cout<<ans;ce;
    }

    return 0;
}

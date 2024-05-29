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
        ll n,x,y;cin>>n>>x>>y;
        v arr(x);
        rep(i,x)
        {
            cin>>arr[i];
        }
       srt(arr);

    ll ans = x-2;
    rep(i,x){
            ll next_dist = (arr[(i+1)%x]-arr[i]+n)%n;
            if(next_dist==2)ans++;
    }
    cout<<ans;ce;
    //     ll max_tri=INT_MIN;
    //     ll tri = x-2;
    //     ll next_dist = (arr[(1)%x]-arr[0]+n)%n;
    //     ll next_next_dist =(arr[(2)%x]-arr[0]+n)%n;
    //     ll prev_dist = (arr[0]-arr[(-1+x)%x]+n)%n;
    //     ll prev_prev_dist =(arr[0]-arr[(-2+x)%x]+n)%n;
    //     if(next_dist==1 && next_next_dist==1)tri--;
    //     if(prev_dist==1 && prev_prev_dist==1)tri--;
    //    rep(i,x)
    //    {
    //     ll next_dist = (arr[(i+1)%x]-arr[i]+n)%n;
    //     if(next_dist==2)tri++;

    //    }

    //    if(n==3)tri=0;
    //    cout<<tri;
    // ll max_  =-2;
    // rep(i,x)
    // {ll val =0;
    //          ll next_dist = (arr[(1)%x]-arr[0]+n)%n;
    //           ll prev_dist = (arr[0]-arr[(-1+x)%x]+n)%n;
    //           if(next_dist==1){val--;}
    //           if(prev_dist==1){val--;}
    // max_ =max(max_,val);
    // }
    // ll ans  =n-2;
    // cout<<ans-(n-2-(x-max_));
    //     ce;

    }

    return 0;
}

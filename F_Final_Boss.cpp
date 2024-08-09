#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
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
int check(ll mid,v &arr,v &cool,ll n,ll h)
{
    ll temp_h = h;
    forb(i,n-1,0)
    {
     
        ll dam =  arr[i];
        ll cools  = cool[i];
        ll times=  ((mid-1)/cools);
     
        temp_h -= times*dam;
        if(temp_h<=0)break;
    }
    if(temp_h<=0)return 1;
    else return 0;
}

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll h,n;
        cin>>h>>n;
        map<ll,ll> counts;
        v arr(n),cool(n);
        ll sum =0;
        rep(i,n){cin>>arr[i];sum+=arr[i];}
        rep(i,n){cin>>cool[i];counts[cool[i]]+=arr[i];}

        ll left  =  0,right = 4*1e10;
        h -= sum;
        while(left+1<right)
        {
            ll mid=  (right-left)/2+left;
            if(check(mid,arr,cool,n,h))right  =mid;
            else left =mid;
        }
        cout<<right;ce;
    }

    return 0;
}

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
int check(ll mid,vector<ll> &arr,ll &mx)
{
    ll two = (mid)/2;
    ll one = (mid+1)/2;
    ll n= arr.size();
    ll flag =1;
    rep(i,n)
    {
        ll copy =arr[i];
        ll times =0;
        if(two)
        {
            times = min(two,(mx-copy)/2);
            two-=times;
            copy+=times*2;
        }
        times = min(one,(mx-copy));
        one-=times;
        copy+=times;
    //    cout<<one<<","<<two<<" ";
    if(mx-copy)flag=0;
    }
    return flag;
}
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
        ll mx  = *(max_element(all(arr)));
        ll ans  = INF;
        for(ll k=mx;k<=mx+1;k++)
        {
            ll left = -1;
            ll right  = 1e15;
            while(left+1<right)
            {
                ll mid = (left+right)/2;
                if(check(mid,arr,k)){right = mid;}
                else left=mid;
                // cout<<mid<<" ";ce;
            }
            ans =min(ans,right);
        }
        cout<<ans;ce;
    }

    return 0;
}
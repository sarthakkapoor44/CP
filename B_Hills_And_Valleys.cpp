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
        vector<int> val(n,0);
        ll ans  =0;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){val[i]=1;ans++;}
            if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){val[i]=-1;ans++;}
        } 
        ll cnt =0;
        ll mx_cnt =0;
        rep(i,n){if(val[i]){cnt++;}else{cnt=0;} mx_cnt = max(mx_cnt,cnt);}
        if(mx_cnt>=3)ans-=3;
        else if(mx_cnt==1)ans-=1;
        else if(mx_cnt ==2)
        {
            ans-=1;
            forf(i,1,n-1)
            {
                if(val[i] && val[i+1])
                {
                    ll a = arr[i-1];
                    ll b = arr[i];
                    ll c= arr[i+1];
                    ll d =arr[i+2];
                    
                    if(i-2>=0 && i+2<n )
                    {
                        ll a_ = arr[i-2];
                        ll d_ = arr[i+2];
                        ll cq=0;
                        if(b>c){
                        if(!(a_<a && c<a) || !(b>d && d_>d)) {ans--;break;}
                        }
                        else
                        {
                            if(!(c>a && a_>a) || !(d>d_ && d>b)){ans--;break;}
                        }
                        
                    }
                    else {ans--;break;}
                }
            }
        } 
        cout<<ans;ce;
    }

    return 0;
}

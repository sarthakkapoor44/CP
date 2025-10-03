///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
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
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 200001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    vector<ll> arr = {1,2,4,6,5,3};
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;cin>>n;
        if(n==1)
        {
            cout<<1;ce;
            cout<<1<<" ";
        }
        else if(n==2)
        {
            cout<<2;ce;
            cout<<1<<" "<<2<<" ";
        }
        else if(n==3)
        {
            cout<<2;ce;
            cout<<1<<" "<<2<<" "<<3<<" ";
        }
        else if(n==4)
        {
            cout<<6;ce;
            cout<<1<<" "<<2<<" "<<3<<" "<<" "<<4;
        }
        else if(n==5){
            cout<<5;ce;
            cout<<2<<" "<<1<<" "<<3<<" "<<4<<" "<<5;
        }
        else
        {
           
            ll cq=0;
            if((n%2))
            {
               cq=1;
               n--; 
            }
            
            ll temp =1;
            while(temp<=n)temp*=2;
            temp/=2;

            if(temp==n)
            {
                if(cq)cout<<n+1;
                else cout<<2*temp-1;
                ce;
                cout<<2<<" ";
                for(int i=4;i<=n-3;i++)cout<<i<<" ";
                cout<<1<<" "<<3<<" "<<n-2<<" "<<n-1<<" "<<n<<" ";
            }
            else
            {
                if(cq)cout<<n+1;
                else cout<<2*temp-1;
                ce;
                for(int i=1;i<=n-2;i++)
                {
                    if(i!=temp-1) cout<<i<<" ";
                }

                cout<<n-1<<" "<<n<<" "<<temp-1<<" ";  
            }
            if(cq)cout<<n+1; 

            }
        
        ce;
        
    }

    return 0;
}





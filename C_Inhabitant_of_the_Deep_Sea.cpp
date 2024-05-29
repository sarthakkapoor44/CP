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
        v arr(n);
        rep(i,n)cin>>arr[i];
        ll start =0,end =n-1;
        ll cnt  =0;
        ll turn =0;
        while(start<=end)
        {
            if((turn%2)==0)
            {
                if(arr[start]<=arr[end])
                {
                    if(k>=2*arr[start]-1)
                    {   arr[end]-=(arr[start]-1);
                        k-=2*arr[start]-1;
                        arr[start]=0;
                        start++;
                        turn=1;
                        cnt++;
                    }
                    else {break;}
                }
                else
                {
                     if(k>=2*arr[end])
                     {  k-=2*arr[end];
                        arr[start]-=arr[end];
                        arr[end] =0;
                        end--;
                        turn=0;
                        cnt++;
                    }
                    else{ break;}
                }
            }
            else 
            {
                if(arr[end]<=arr[start])
                {
                    if(k>=2*arr[end]-1)
                    {   arr[start]-=(arr[end]-1);
                        k-=2*arr[end]-1;
                        arr[end]=0;
                        end--;
                        turn=0;
                        cnt++;
                    }
                    else {break;}
                }
                else
                {
                     if(k>=2*arr[start])
                     {  k-=2*arr[start];
                        arr[end]-=arr[start];
                        arr[start] =0;
                        start++;
                        turn=1;
                        cnt++;
                    }
                    else{ break;}
                }
            }
        }
        if(start== end && arr[start]!=0 && k>=arr[start]){k-=arr[start];cnt++;arr[start]=0;}
        cout<<cnt;ce;
    }

    return 0;
}

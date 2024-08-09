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
        v prefix(n),suffix(n);
        rep(i,n)
        {
            prefix[i] = i?prefix[i-1]+arr[i]:arr[i];
        }
        forb(i,n-1,0)
        {
            suffix[i] = (i-n+1)?suffix[i+1]+arr[i]:+arr[i];
        }
        ll val1=-1;
        ll val2=-1;
        v diff_left(n,INF),diff_right(n,INF);
        rep(i,n)
        {
           if(val1==-1 || arr[i]!=arr[val1])
           {
                val2 =val1;
                val1 = i;
                if(val2!=-1){diff_left[i] = i-val2;}
           }
           else
           {
                val1 = i;
                if(val2!=-1){diff_left[i] = i-val2;}
           }
        }

        val1=-1;
        val2=-1;
        forb(i,n-1,0)
        {
           if(val1==-1 || arr[i]!=arr[val1])
           {
                val2 =val1;
                val1 = i;
                if(val2!=-1){diff_right[i] = val2-i;}
           }
           else
           {
                val1 = i;
                if(val2!=-1){diff_right[i] = val2-i;}
           }
        }
        reverse(all(suffix));
       
        rep(i,n)
        {
            
                auto x = upper_bound(all(prefix),prefix[i]+arr[i])-prefix.begin();
                ll idx = n-i-1;
                ll ans = INF;
                auto y = suffix.end()-1-upper_bound(all(suffix),suffix[idx]+arr[i]);
                // cout<<i<<" "<<x<<" "<<y<<" "<<" "; 
                if(x<n)
                {
                    if(x-i==1)ans=1;
                    else
                    {

                        if(diff_left[x]>=(x-i))
                        {
                            ll index = diff_right[x];
                            if(index!=INF)
                            {
                                ans = index;
                            }
                        }
                        else ans = (x-i);
                    }
                }
                if(y>=0)
                {
                    if(i-y==1){ans=1;}
                    else {
                        if(diff_right[y]>=(i-y))
                        {
                            ll index = diff_left[y];
                            if(index!=INF)
                            {
                                ans = min(ans,index);
                            }
                        }
                        else ans = min(ans,(i-y));
                    }
                }
                if(ans==INF)cout<<-1<<" ";
                else cout<<ans<<" ";
                // ce;
        }
        ce;
    }

    return 0;
}

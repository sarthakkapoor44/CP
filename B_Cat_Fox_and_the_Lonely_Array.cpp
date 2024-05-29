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
const ll MAXN = 100001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
vector<vector<int> > bits(MAXN,vector<int>(20,0));
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
        ll tot=0;
        rep(i,n)
        {
            cin>>arr[i];
            tot|=arr[i];
        }
        rep(i,n)
        {
            rep(j,20)
            {
                if((arr[i]&(1ll<<j)))
                {
                    bits[i][j]=1;
                }
                else
                {
                    bits[i][j]=0;
                }
            }
        }
        ll right = n;
        ll left = 0;
        while(left+1<right)
        {
            ll mid = (right+left)/2;
            if(mid>n)break;
            ll val =0;
            vector<int> curr(mid,0);
            
            rep(i,mid)
            {
                val|=arr[i];
                rep(j,20)
                {
                    curr[j]+=bits[i][j];
                }
            }
            if(tot!=val){left=mid;continue;}
            ll cq=1;
            forf(i,mid,n)
            {
                ll start = i-mid;
                rep(j,20)
                {
                    int final = curr[j]-bits[start][j]+bits[i][j];
                    if(curr[j])
                    {
                        if(!final){cq=0;break;}
                    }
                    else 
                    {
                        if(final){cq=0;break;}
                    }
                    curr[j]=final;
                }
                if(!cq)break;
            }

            if(!cq)left=mid;
            else right=mid;
            if(left==n)break;
        }
        cout<<right;ce;
        
    }

    return 0;
}

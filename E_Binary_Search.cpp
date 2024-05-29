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
        ll n,x;
        cin>>n>>x;
        v arr(n+1);
        ll curr;
        forf(i,1,n+1){cin>>arr[i];if(arr[i]==x){curr=i;}}
        ll left=1,right=n+1,mid =(left+right)/2;
        vp idx;
        while((left+1)!=right)
        {   mid= (left+right)/2;
        // cout<<mid<<" "<<left<<" "<<right;ce;
            if(arr[mid]<=x){left=mid;}
            else {right=mid;}
            // if(left+1==right)break;

            idx.pb(mp(arr[mid],mid));
        }
        // mid =(left+right)/2;
        //  idx.pb(mp(arr[mid],mid));
        // rep(i,idx.size())cout<<idx[i].fi<<" ";ce;
        if(arr[left]==x)cout<<0;
        else{
            ll last_idx= INF;
            rep(i,idx.size()){if(idx[i].fi<=x){last_idx=idx[i].se;}}
            if(last_idx!=INF){
               if(last_idx!=curr) cout<<1<<endl<<curr<<" "<<last_idx;
                else cout<<0;
                }
            else
            {
                cout<<1<<endl<<left<<" "<<curr;
            }
        }
    ce;
    }

    return 0;
}

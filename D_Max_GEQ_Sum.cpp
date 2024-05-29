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
        ll tot_sum =0;
        rep(i,n){cin>>arr[i];tot_sum+=arr[i];}
        queue<ll> max;
        max.push(arr[0]);
        // stack<ll> rev_max;
        // rev_max.push(arr[0]);
        forf(i,1,n)
        {
            if(arr[i]>max.front()){max.push(arr[i]);}
        } 

        set<ll> presum,postsum;
        ll sum = 0;
        presum.insert(0);
        ll cq=1;
        rep(i,n)
        {
            if(max.empty())break;
            sum+=arr[i];
            ll min_pre = *presum.begin();
            ll val =  sum-min_pre;
            if(arr[i]==max.front())
            {
                max.pop();
                if(arr[i]<val){cq=0;break;}
            }
           
            presum.insert(sum);
        }
        ll max_ = 0;
        sum = 0;
        postsum.insert(0);
        forb(i,n-1,0)
        {
            sum+=arr[i];
            ll min_post = *postsum.begin();
            ll val =  sum-min_post;
            if(arr[i]>max_)
            {
                sum=0;
                max_=0;
                postsum.clear();
                if(arr[i]<val){cq=0;break;}
            }
           postsum.insert(sum);
        }

        if(!cq){pno;}
        else pyes;
        ce;
        
    }

    return 0;
}

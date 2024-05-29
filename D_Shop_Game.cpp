///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
   tree_order_statistics_node_update> ost;
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
    
   
    {   //Lesgooooooo!!!!
    int A;ll B;
    cin>>A>>B;
    int n =A;
    vector<long long > factorial(n,1e18+1);
    factorial[0]=1;
    ost idx_set;
    rep(i,A)
    {
        idx_set.insert(i+1);
    }
    for(int i=1;i<n;i++)
    {
        factorial[i]= (factorial[i-1]*i);
        if(factorial[i]>=B)break;
    }
    int i=1;
    vector<int> ans;
    vector<int> cq(n+1,0);
    while(B>0)
    {
        ll val  = B/factorial[n-i];
        B-= val*factorial[n-i];
        
        if(B)val++;
        ll idx = *idx_set.find_by_order(val-1);
        idx_set.erase(idx);
        ans.push_back(idx);
        cq[idx]=1;
        if(!B)
        {
          if(idx_set.size()>=2)  {ll last = *idx_set.find_by_order(1);
            ans.push_back(last);
            cq[last]=1;}
        }
        i++;
        if(i>=n)break;
    }
    for(int j=1;j<=n;j++)
    {
        if(!cq[j])ans.push_back(j);
    } 
    for(auto x:ans)cout<<x<<" ";ce;

    }

    return 0;
}

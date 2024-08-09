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
const ll MAXN = 1.5*10000000;
const ll modn = 998244353;


vector<int> check(MAXN+1,0);
vector<int> lp(MAXN+1);
vector<int> pr;

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
 
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v arr(n);
        scanf("%lld",&arr[0]);
        ll gcd_ = arr[0];
        ll max_val=arr[0];
        forf(i,1,n){scanf("%lld",&arr[i]);gcd_ =gcd(gcd_,arr[i]);max_val=max(max_val,arr[i]);}
        for(int i=2;i<=MAXN;i++)
        {
            if(lp[i]==0)
            {
                lp[i]=i;
                pr.push_back(i);
            }
            for(int j=0;i*pr[j]<=MAXN;j++)
            {
                lp[i*pr[j]]= pr[j];
                if(pr[j]==lp[i])break;
            }

        }
        rep(i,n)
        {
            ll val = arr[i]/gcd_;
            while(val>1) 
            {
                check[lp[val]]++;
                while(!(val%lp[val]))val/=lp[val];
            }
        }
        ll ans  =0;
        rep(i,MAXN+1)ans =max(ans,(ll)check[i]);
        if(ans)printf("%lld",n-ans);
        else printf("%d",-1);
        ce;
        }

    return 0;
}

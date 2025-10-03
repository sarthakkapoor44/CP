///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#include<iomanip>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define INF 1000000000000000000
#define pi 3.141592653589793238462643383279502884197169399
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
const ll MAXN = 1000001;
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

long double custom_sqrtl(long double x) {
    if (x < 0.0L) {
        // Square root of a negative number is not defined in real numbers
        return std::numeric_limits<long double>::quiet_NaN();
    }
    if (x == 0.0L || x == 1.0L) {
        return x;
    }

    long double guess = x / 2.0L;
    const long double epsilon = 1e-15L; // Adjust the precision as needed

    while (true) {
        long double next_guess = 0.5L * (guess + x / guess);
        if (fabsl(next_guess - guess) < epsilon) {
            break;
        }
        guess = next_guess;
    }
    return guess;
}

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ld x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        ld temp1  =(x1-x2)*(x1-x2);
        ld temp2  =(y1-y2)*(y1-y2);
        ld dsq = temp1+temp2;
        ld ans = 0;
        ld r1sq = r1*r1;
        ld r2sq = r2*r2;
        ld d = sqrtl(dsq);
        if(dsq>=(r1sq + r2sq + 2*r1*r2))ans = 0;
        else if(dsq <= (r1sq + r2sq -2*r1*r2))ans = pi*min(r1sq,r2sq);
        else
        {

            ld cos2 = (dsq - r1sq +r2sq)/(2*r2*d) ;
            ld cos1 = (dsq - r2sq + r1sq)/(2*r1*d) ;
            ld theta1 =acos(cos1); 
            ld theta2 =acos(cos2); 
            ld sin1  =sqrtl(1-cos1*cos1);
            ld sin2 = sqrtl(1-cos2*cos2);
            ld arc1  = r1sq*theta1;
            ld arc2  = r2sq*theta2;
            ld tri1 = r1sq*sin1*cos1;
            ld tri2 = r2sq*sin2*cos2;
            ld ar1  =arc1-tri1;
            ld ar2 = arc2-tri2;
            ans = ar1+ar2;
        }
        cout<<setprecision(20)<<ans;ce;
        
    }

    return 0;
}

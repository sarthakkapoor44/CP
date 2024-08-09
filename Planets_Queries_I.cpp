///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
const int l =30;
const int N= 2e5+1;
int succ[N][l];
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
   
    {	//Lesgooooooo!!!!
        int n,q;
        scanf("%d%d",&n,&q);
        int num ;
        for(int i=0;i<n;i++)
        {

           scanf("%d",&num);
           succ[i][0]=num-1;
        }
        for(int j = 1;j<l;j++)
        {
            for(int i=0;i<n;i++)
            {
               if(succ[i][j-1]==-1){break;}succ[i][j] = succ[succ[i][j-1]][j-1];
            }
        }
        int a,b;
        for(int i=0;i<q;i++)
        {
           
            scanf("%d%d",&a,&b);
            a--;
            for(int j=0;j<=l;j++){
                if((b&(1<<j)))a = succ[a][j];
            }
           printf("%d\n",a+1);
        }
        
    }
 
    return 0;
}
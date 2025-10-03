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
#define pll pair<ll,ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr = {1,2,3};
        vll temp[3];
        ll count=3;
        cout<<"? "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        cout.flush();
        ll inp;cin>>inp;
        temp[0] = {inp,2,3};
        temp[1] = {1,inp,3};
        temp[2] = {1,2,inp};
        ll cq=0;
        if(inp ==0)
        {
            cout<<"! "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
            cout.flush();
        }
        else
        {
            while(1)
            {
                rep(j,3)
                {
                    cout<<"? "<<temp[j][0]<<" "<<temp[j][1]<<" "<<temp[j][2]<<endl;
                    cout.flush();
                    ll inp;cin>>inp;
                    if(inp == 0)
                    {
                        cout<<"! "<<temp[j][0]<<" "<<temp[j][1]<<" "<<temp[j][2]<<endl;
                        cout.flush();
                        cq=1;
                        break;
                    }
                    if(inp ==-1)break;
                    else 
                    {
                        count++;
                        if(j == 0)
                        {
                            temp[0] = {inp,temp[0][1],temp[0][2]};
                        }
                        else if(j == 1)
                        {
                            temp[1] = {temp[1][0],inp,temp[1][2]};
                        }
                        else
                        {
                            temp[2] = {temp[2][0],temp[2][1],inp};
                        }
                        if(count == n)
                        {
                            cout<<"! "<<temp[j][0]<<" "<<temp[j][1]<<" "<<temp[j][2]<<endl;
                            cout.flush();
                            cq=1;
                            break;
                        }
                    }
                }
                if(cq)break;
            }
        }

    } 
        
    return 0;
}


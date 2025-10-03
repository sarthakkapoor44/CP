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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vll arr1(n),arr2(n);
        rep(i,n){cin>>arr1[i];}
        rep(i,n)cin>>arr2[i];
        ll left  =0 ,right = 1e9;
        ll final_sum = 0,final_moves= 0,final_val =0;
        vector<ll> vect(n);
        while(left<=right)
        {
            ll mid  = (left+right)/2;
            ll sum =0 ,moves = 0;
            vector<ll> vects(n);
            rep(i,n)
            {
                if(arr1[i]>=mid)
                {

                    ll mov = ceil((arr1[i]-mid)*1.0/(arr2[i]));
                    ll to_add =0 ;
                    if(arr1[i]-arr2[i]*mov<0){to_add = (mov-1)*arr1[i] - (((mov-1)*(mov-2))/2)*arr2[i]+(arr1[i]%arr2[i]); }
                    else to_add = mov*arr1[i] - ((mov*(mov-1))/2)*arr2[i]; 
                    vects[i] = max(0ll,arr1[i] - arr2[i]*(mov));
                    moves += mov;
                    sum += to_add;
                    if(moves>k)break;
                }
            }
            if(moves>k)left = mid+1;
            else
            {
            
                vect = vects;
                final_val = mid;
                final_moves = moves;
                final_sum = sum;
                right = mid-1;
            }
        }
        // cout<<final_sum<<" "<<final_moves<<" "<<final_val<<" ";
        k -= final_moves;
        if(k>0 )
        {
            priority_queue<pair<ll,ll>> pq;
            rep(i,n){if(vect[i]>0 )pq.push({vect[i],arr2[i]});}
            while(k>0 && pq.size())
            {
                auto [fir,sec] = pq.top();
                pq.pop();
                final_sum += fir;
                fir=max(0ll,fir-sec);
                if(fir>0)pq.push({fir,sec});
                k--;
            }
        }
        // debug(vect);
        cout<< final_sum;ce;
        
    }

    return 0;
}

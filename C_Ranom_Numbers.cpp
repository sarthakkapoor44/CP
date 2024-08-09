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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        string s;
        cin>>s;
        ll n = s.length();
        ll ans  = 0;
       

        vector<vector<ll>> pre(n+1,vector<ll>(5,0)),pre_left(n+1,vector<ll>(5,0)),post(n+1,vector<ll>(5,0));
        vector<ll> val(5,0);
        for(ll i=0;i<n;i++)
        {
            ll pos = s[i]-'A';
            for(ll j = 0;j<pos;j++)
            {
                pre[i+1][j]+= val[j];
                val[j] = 0;
            }
            for(ll j =pos;j<5;j++){
                pre_left[i+1][j]+= val[j];
             
            }
            val[pos] ++;
        }
   
        for(ll i = n-1;i>=0;i--)
        {
            ll pos = s[i] - 'A';
            ll  flag= 0;
            for(ll j = 0;j<5;j++)
            {
                post[i][j] = post[i+1][j] + (pos == j );
                if(j>pos && post[i+1][j])flag =1;
            }
            ans+= pow(10,pos)*pow(-1,flag);
        }
        // cout<<ans;ce;
        ll mx_temp = 0;
        for(ll i=0;i<n;i++)
        {
            ll pos  = s[i]-'A';
            
            vector<ll> grt(5,0);
      
            for(ll j=3;j>=0;j--)
            {
                grt[j]= (j<4?grt[j+1]:0) + post[i+1][j+1];
            }
            for(ll j=0;j<5;j++)
            {
                ll temp = 0;
                if(grt[pos])temp+= pow(10,pos);
                else temp -= pow(10,pos);
                // cout<<i<<" "<<temp<<" "<<grt[pos]<<" ";
                if(grt[j])temp -= pow(10,j);
                else temp += pow(10,j);
                // cout<<temp<<" ";
                if(j<pos)
                {
                    for(ll k =j;k<pos;k++)
                    {
                        if(!grt[k]){temp+= 2*pre[i+1][k]*pow(10,k);}
                    }
                    mx_temp = max(mx_temp,temp);
                }
                else if(j>pos)
                {
                    for(ll k =pos;k<j;k++)
                    {
                        if(!grt[k]){temp -= 2*pre_left[i+1][k]*pow(10,k);}
                    }
                    mx_temp = max(mx_temp,temp);
                }

                // cout<<j<<" "<<temp<<endl;
            }
        }
    
        ans = max(ans,ans+mx_temp);
        // debug(pre_left);
        // debug(post);
        
        cout<<ans<<endl;
    }

    return 0;
}

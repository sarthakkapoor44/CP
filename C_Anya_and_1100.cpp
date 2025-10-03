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
        string s;cin>>s;
        ll n = s.length();
        ll q;cin>>q;
        ll cnt= 0;
        vll vis(n);
        rep(i,n)
        {
            if(s[i] == '1')
            {
                if(i+1<n && s[i+1]=='1')
                {
                    if(i+2<n && s[i+2]=='0')
                    {
                        if(i+3<n && s[i+3]=='0')
                        {
                            cnt++;
                            for(int j =i;j<=i+3;j++)vis[j]=1;
                        }
                    }
                }
            }
        }
        // debug(cnt);
        while(q--)
        {
            
            
                ll a,b;
                cin>>a>>b;
                a--;
                // cout<<s;ce;
                char val = '0'+b;
                if(s[a] == val)
                {
                    if(cnt)pyes;
                    else pno;
                    // cout<<s[a]<<" "<<val;ce;
                }
                else if(b==0)
                {
                    
                     if(vis[a])
                    {
                        cnt--;
                         if(a+1<n && s[a+1]=='1')
                        {
                            if(a+2<n && s[a+2]=='0')
                            {
                                if(a+3<n && s[a+3]=='0')
                                {
                                    vis[a]=0;vis[a+1]=0;vis[a+2]=0;vis[a+3]=0;
                                    // cnt++;
                                }
                            }
                        }

                        if(a-1>=0 && s[a-1]=='1')
                        {
                            if(a+1<n && s[a+1]=='0')
                            {
                                if(a+2<n && s[a+2]=='0')
                                {
                                    // cnt++;
                                    vis[a-1]=0;vis[a]=0;vis[a+1]=0;vis[a+2]=0;
                                }
                            }
                        }
                    }
                    if(!vis[a])
                    {   
                        if(a-1>=0 && s[a-1]=='1')
                        {
                            if(a-2>=0 && s[a-2]=='1')
                            {
                                if(a+1<n && s[a+1]=='0')
                                {
                                    vis[a]=1;vis[a-1]=1;vis[a-2]=1;vis[a+1]=1;
                                    cnt++;
                                }
                            }
                        }

                        if(a-1>=0 && s[a-1]=='0')
                        {
                            if(a-2>=0 && s[a-2]=='1')
                            {
                                if(a-3>=0 && s[a-3]=='1')
                                {
                                    cnt++;
                                    vis[a-1]=1;vis[a]=1;vis[a-2]=1;vis[a-3]=1;
                                }
                            }
                        }
                    }
                    s[a] ='0';
                    if(cnt)pyes;
                    else pno;
                }
                else
                {
                    if(vis[a])
                    {
                        cnt--;
                        if(a-1>=0 && s[a-1]=='1')
                        {
                            if(a-2>=0 && s[a-2]=='1')
                            {
                                if(a+1<n && s[a+1]=='0')
                                {
                                    vis[a]=0;vis[a-1]=0;vis[a-2]=0;vis[a+1]=0;
                                    // cnt++;
                                }
                            }
                        }
                        if(a-1>=0 && s[a-1]=='0')
                        {
                            if(a-2>=0 && s[a-2]=='1')
                            {
                                if(a-3>=0 && s[a-3]=='1')
                                {
                                    // cnt++;
                                    vis[a-1]=0;vis[a]=0;vis[a-2]=0;vis[a-3]=0;
                                }
                            }
                        }
                    }
                    if(!vis[a])
                    {
                         if(a+1<n && s[a+1]=='1')
                        {
                            if(a+2<n && s[a+2]=='0')
                            {
                                if(a+3<n && s[a+3]=='0')
                                {
                                    vis[a]=1;vis[a+1]=1;vis[a+2]=1;vis[a+3]=1;
                                    cnt++;
                                }
                            }
                        }

                        if(a-1>=0 && s[a-1]=='1')
                        {
                            if(a+1<n && s[a+1]=='0')
                            {
                                if(a+2<n && s[a+2]=='0')
                                {
                                    cnt++;
                                    vis[a-1]=1;vis[a]=1;vis[a+1]=1;vis[a+2]=1;
                                }
                            }
                        }
                    }
                    s[a]= '1';
                    if(cnt)pyes;
                    else pno;

            }
            ce;
        }
        
        
    }

    return 0;
}

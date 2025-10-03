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
        ll n,m;
        cin>>n>>m;
        vector<string> grid(n);
        
        rep(i,n)
        {
            cin>>grid[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll>(5,-INF));
        dp[0][0] =0 ;
        vector<vector<string>> frag(n);
        vector<char> word = {'n','a','r','e','k'};
        vector<int> cnts(n),neg_counts(n);
        rep(i,n)
        {
            ll idx = 0;
            ll cnt = 0;
            ll last = -1;
            ll start = -1;
            ll tot_cnt = 0;
            rep(j,m)
            {
                for(auto x:word)
                {
                    if(x == grid[i][j])tot_cnt++;
                 }
                if(word[idx] == grid[i][j])
                {
                    start = (start==-1)?j:min(start,j);
                    cnt+= (idx/4);
                    if(cnt && (idx==4))last= j;
                    idx = (idx+1)%5;
                }
            }
            vector<string> inner_frag(2);
            cnts[i]= 5*cnt;
            string pre="" ,suf= "";
            if(cnt)rep(j,start)pre += grid[i][j];
            forf(j,last+1,m)suf+= grid[i][j];
            inner_frag = {pre,suf};
            frag[i] = inner_frag;
            neg_counts[i] = -tot_cnt + cnts[i];
            // debug(start,last);
        }
        forf(i,1,n+1)
        {
            rep(k,5)
            {
                dp[i][k] = max(dp[i][k],dp[i-1][k]);
                if(dp[i-1][k]>-INF)
                {
                    if(cnts[i-1])
                    {
                        ll cq = 0 ;
                        if(frag[i-1][0].size())
                        {
                            ll idx=  k;
                            for(auto x :frag[i-1][0])
                            {
                                if(x == word[idx])
                                {
                                    idx++ ;
                                    if(idx == 5){cq=1;break;}
                                }
                            }
                        }
                        ll val = dp[i-1][k] + cnts[i-1] + neg_counts[i-1] + ((cq>0)?10:0) ;
                        dp[i][0] = max(dp[i][0],val);
                        
                        ll idx= 0 ;
                        if(frag[i-1][1].size())
                        {
                            for(auto x:  frag[i-1][1])
                            {
                                if(word[idx] == x)
                                {
                                    idx++;
                                    dp[i][idx] = max(dp[i][idx],val);
                                }
                            }
                        }
                    }
                    else
                    {
                        string temp = frag[i-1][1];
                        ll idx= 0;
                        if(temp.size())
                        {
                            for(auto x:  temp)
                            {
                                if(word[idx] == x)
                                {
                                    idx++;
                                    dp[i][idx] = max(dp[i][idx],dp[i-1][k] + neg_counts[i-1] + cnts[i-1]);
                                }
                            }
                            idx= k; 
                            ll cq = 0 ;
                            ll jidx =0;    
                            for(jidx= 0 ;jidx<temp.size();jidx++)
                            {
                                if(temp[jidx] == word[idx])
                                {
                                    idx++ ;
                                    if(idx == 5){cq=1;break;}
                                }
                            }
                            if(cq)
                            {
                                dp[i][0] = max(dp[i][0],dp[i-1][k] +neg_counts[i-1] + 10 );
                                idx= 0 ;
                                for(int p = jidx+1;p<temp.size();p++)
                                {
                                    if(word[idx] == temp[p])
                                    {
                                        idx++;
                                        dp[i][idx] = max(dp[i][idx],dp[i-1][k] + neg_counts[i-1] + 10 );
                                    }
                                }
                            }
                            
                        }

                    }
                }
            }
        }
        // debug(dp,frag);
        ll ans = 0;
        rep(i,5)
        {
            ans = max(ans,dp[n][i]);
        }
      
       cout<<ans;ce;
    }

    return 0;
}

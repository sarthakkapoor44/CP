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
   
        string s;
        cin>>s;
        ll l =0 ,r= s.length()-1; 
        while(l<r)
        {
            if(s[l] == s[r]){l++;r--;}
            else break;
        }
        ll ans = 0;
        if(l < r)
        {   
            ans = r-l+1;
            vector<ll> tot(26,0) ;
            for(int i = l;i<=r;i++)tot[s[i]-'a']++;
            ll midl = (l+r)/2;
            ll midr = (l+r+1)/2;
    
            bool odd = 0;
            if(midl == midr)odd=1;
            if((midl != midr) || (midl == midr && (tot[s[midl]-'a']%2)==1))while(s[midl]== s[midr]){midl--;midr++;}
         
            vll pre(26,0),suf(26,0);
            ll left = l,right = r;
            while(left<midl)
            {
                pre[s[left]-'a']++;
                left++;
                suf[s[right]-'a']++;
                right--;
            }
            if(midl!=midr)
            {
                pre[s[midl]-'a']++;
                suf[s[midr]-'a']++;
            }
            else pre[s[midl]-'a']++;
            // debug(l,r,midl,midr,pre,suf,ans);
            ll odd_cnt=0 ;
            bool cq=1;
            for(int i=0;i<26;i++)
            {   
                if(pre[i]!=suf[i])
                {
                    if(abs(pre[i]-suf[i])>1)cq=0;
                    else odd_cnt++;
                }
            }
            if(odd_cnt>1)cq=0;
            if(cq){ans = midl - l+1;}
            else
            {
                midl = (l+r)/2;
                midr = (l+r+1)/2;       
                pre.clear();pre.resize(26,0);
                suf.clear();suf.resize(26,0);

                for(int i =l;i<midr;i++)pre[s[i]-'a']++;
                for(int i = r;i>=midr;i--)suf[s[i]-'a']++;
                // debug(ans,pre,suf);
                bool fl =1 ;
                for(int j =0;j<26;j++)
                {
                    if(pre[j] >=suf[j])
                    {
                        if((pre[j]-suf[j])%2==1)odd_cnt++;
                        if((odd_cnt && !odd) || (odd && odd_cnt>1) ){fl = 0;break;}
                    }
                    else {fl=0;break;}
                }
                if(fl)ans = min(ans,midr-l);

                for(int i = midr;i<=r;i++)
                {
                    
                    suf[s[i]-'a']--;
                    pre[s[i]-'a']++;
                    odd_cnt=0;
                    fl=1;
                    for(int j =0;j<26;j++)
                    {
                        if(pre[j] >=suf[j])
                        {
                            if((pre[j]-suf[j])%2==1)odd_cnt++;
                            if((odd_cnt && !odd) || (odd && odd_cnt>1) ){fl = 0;break;}
                        }
                        else {fl=0;break;}
                    }
                    if(fl){ans = min(ans,i-l+1);break;}
                }

                pre.clear();pre.resize(26,0);
                suf.clear();suf.resize(26,0);
                for(int i =l;i<=midl;i++)pre[s[i]-'a']++;
                for(int i = r;i>midl;i--)suf[s[i]-'a']++;

                for(int j =0;j<26;j++)
                {
                    if(pre[j] <=suf[j])
                    {
                        if((suf[j]-pre[j])%2==1)odd_cnt++;
                        if((odd_cnt && !odd) || (odd && odd_cnt>1) ){fl = 0;break;}
                    }
                    else {fl =0;break;}
                }
                if(fl){ans = min(ans,r-midl);}

                for(int i = midl;i>=l;i--)
                {
                    pre[s[i]-'a']--;
                    suf[s[i]-'a']++;
                    odd_cnt=0;
                    fl=1;
                    for(int j =0;j<26;j++)
                    {
                        if(pre[j] <=suf[j])
                        {
                            if((suf[j]-pre[j])%2==1)odd_cnt++;
                            if((odd_cnt && !odd) || (odd && odd_cnt>1) ){fl = 0;break;}
                        }
                        else {fl =0;break;}
                    }
                    if(fl){ans = min(ans,r-i+1);break;}
                }

            }
        }
        cout<<ans;ce;
    }

    return 0;
}

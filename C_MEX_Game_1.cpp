#include<bits/stdc++.h>
using namespace std;
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
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

int mex(ll mid,vp times)
{       int cq=1;
        ll cnt = 0;
        ll ti = 0;
        rep(i,times.size())
        {
            if(times[i].se<mid)
            {
                if(times[i].fi==1)ti++;
                if(ti<=1)
                {
                    cnt++;
                }
                else {cq= 0 ;break;}
                
            }
        }
        if(cnt!=mid)cq=0;
        return cq;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int t=1;
    cin>>t;
    while (t--)
    {   
        ll n;
        cin>>n;
        v arr(n);rep(i,n)cin>>arr[i];
        v cnt(n,0);rep(i,n)cnt[arr[i]]++; 
        ll cnts=0;
        ll ans = n;
        rep(i,n)
        {
            if(cnt[i]==1)cnts++;
            if((!cnt[i]) || cnts>1){ans =i;break;}
            
        }
        cout<<ans;ce;
    }
// void arr[2];

    return 0;
}

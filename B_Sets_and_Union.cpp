#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
/*ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
     
        v temp (51,0);
        vector<vector<ll> > ip (n,temp);
        ll final[51];
        memset(final,0,sizeof(final));
        rep(i,n){
            ll a;cin>>a;
            rep(j,a){
                ll num;cin>>num;
                final[num]+=1;
                ip[i][num]=1;
            }
        }
        
    
    }
return 0;
}

//     ll cm =INT_MIN;
    //     ll count=0;
    //    rep(i,n){
    //     ll flag=0;
    //     forf(j,1,51){
    //         if(final[j]-ip[i][j]>0){count++;}
    //         else if(final[j]==1  && ip[i][j]==1){flag=1;}
            
    //     }
    //     cout<<count<<" ";
    //     if(flag==1){cm = max(cm,count);}
    //     count=0;
    //     flag=0;
    //    }ce;ce;
    //    cout<<cm;ce;
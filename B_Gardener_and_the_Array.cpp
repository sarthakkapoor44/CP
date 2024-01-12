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
        vector<vector<ll> > ip;
      v temp;
unordered_map<ll,ll> arr;
    //  rep(i,2*1e5+1){arr[i]=0;}
        rep(i,n){
            ll a;cin>>a;
          temp.clear();
            rep(j,a){
                ll num;
                cin>>num;
                temp.pb(num);
                arr[num]+=1;
                }
            ip.pb(temp);
        }
    
    ll ans =0;
    rep(i,n){
        ll flag=0;
        rep(j,ip[i].size()){
            
            if(arr[ip[i][j]]==1){flag=1;break;}

           
        }
         if(!flag){ans=1;break;}
      
    }
    if(ans){pyes;}else{pno;}ce;
    }
return 0;
}
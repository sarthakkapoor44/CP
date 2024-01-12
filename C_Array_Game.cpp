#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
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
        ll n,k;
        cin>>n>>k;
        ll ans =0;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        sort(arr,arr+n);
        if(k<3){

            vp diff;
            rep(i,n){
                forf(j,i+1,n){
                    diff.pb(mp(arr[j]-arr[i],1));
                }
            }
            
           rep(i,n){diff.pb(mp(arr[i],0));}
           srt(diff);
           ans= diff[0].fi;
           if(k==2){
            srt(diff);
            // rep(i,diff.size()){cout<<diff[i]<<" ";}ce;
            ll last_1=0,last_0=0;
            rep(i,diff.size()-1){
                if(diff[i].se==1 ){last_1=max(last_1,diff[i].fi);}
                else if(diff[i].se==0){last_0 = max(last_0,diff[i].fi);}
              ans= min(abs(last_1-last_0),ans);
                }
            }
           }

        
        cout<<ans;ce;
    }
return 0;
}
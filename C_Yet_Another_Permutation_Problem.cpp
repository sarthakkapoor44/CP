#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end
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
void gen(vp &temp,ll n, ll i,ll arr[]){
    ll flag = 0;
    for(int j=2;j*j<=temp[i].se;j++){
        if(temp[i].se%j==0){
        if(arr[(temp[i].se/j)]==0){temp[i].fi =temp[i].se/j;arr[temp[i].fi]=1; flag=1;break;}
        }
    }
    if(flag==0){temp[i].fi = temp[i].fi;}
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vp temp;
        ll arr[n+1];
        memset(arr,0,sizeof(arr));
        forf(i,1,n+1){
            temp.pb(mp(i,i));
        }
        rep(i,n){gen(temp,n,i,arr);}
        // srt(temp);
        //  rep(i,n){cout<<temp[i].se<<"->"<<temp[i].fi<<" ";}ce;
        ll ans[n+1];
        memset(ans,0,sizeof(ans));
        rep(i,n){
            if(temp[i].fi!=temp[i].se){
                ans[temp[i].fi]=temp[i].se;
            }
        }
         memset(arr,0,sizeof(arr));
    rep(i,n){
           if(temp[i].fi==temp[i].se && arr[temp[i].se]==0){
            cout<<temp[i].fi<<" ";
            ll index =temp[i].se;
            while(index<=n && ans[index]!=0){
                cout<<ans[index]<<" ";
                arr[index]=1;
                index = ans[index];
            }
           }
            }ce;
        // forf(i,1,n+1){cout<<i<<"->"<<ans[i]<<" ";}ce;
    }
return 0;
}
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
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll mx = n;
        if(n>1)
        {
        if(arr[0]==n){mx--;}
        ll mxindex;
        rep(i,n){if(arr[i]==mx){mxindex =i;break;}}
        v ans;
        set<vector<ll> > check;
        forf(i,mxindex,n){ans.pb(arr[i]);}
        forb(i,mxindex-1,0)
        {   v front;
            forb(j,mxindex-1,i){front.pb(arr[j]);}
            rep(j,i){front.pb(arr[j]);}
            check.insert(front);
        }        
        v last;
        if(mxindex= n-1){
            last.pb(arr[n-1]);
            rep(i,n-1){last.pb(arr[i]);}
        }
        v final = *(--check.end());
        rep(i,final.size()){ans.pb(final[i]);}
        if(last.size()!=0){
            vector<vector<ll > > sorts;
            sorts.pb(ans);
            sorts.pb(last);
            srt(sorts);
            ans = sorts[1];
        }
        rep(i,n){cout<<ans[i]<<" ";}
        }
        else{cout<<arr[0]<<" ";}
        ce;
    }
return 0;
}
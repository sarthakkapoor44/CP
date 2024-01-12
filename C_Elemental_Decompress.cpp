#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) (s.begin(),s.end)
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
        vp arr;
        rep(i,n){ll num;cin>>num;arr.pb(mp(num,i));}
        srt(arr);
        // ll ord[n],arr[n];
        // rep(i,n){arr[i]=vect[i].fi;ord[i]=vect[i].se;}
        // sort(ord, ord + n, [&](int i, int j) { return arr[i-1] < arr[j-1];});
        // rep(i,n){cout<<ord[i];}ce;
        // sort(arr,arr+n);
        
        map<ll,ll> count;
        ll ans=1;
        rep(i,n){count[arr[i].fi]+=1;if(count[arr[i].fi]>2){ans=0;break;}}
        if(count[n]==0){ans=0;}
        vp p1,p2;
        if(ans){
            queue<ll> unused;
            forf(i,1,n+1){if(count[i]==0){unused.push(i);}}
            rep(i,n){
                if(count[arr[i].fi]==1){p1.pb(mp(arr[i].se,arr[i].fi));p2.pb(mp(arr[i].se,arr[i].fi));}
                else{
                    if(unused.front()>arr[i].fi){ans=0;break;}
                    p1.pb(mp(arr[i].se,arr[i].fi));p1.pb(mp(arr[i+1].se,unused.front()));
                    p2.pb(mp(arr[i].se,unused.front()));p2.pb(mp(arr[i+1].se,arr[i].fi));
                    i+=1;
                    if(!unused.empty())unused.pop();
                }
            }
            if(ans){
            pyes;ce;
            // sort(p1.begin(),p1.end(),[&](int i, int j) { return ord[i-1] < ord[j-1];});
             srt(p1);srt(p2);
            rep(i,n){cout<<p1[i].se<<" ";}ce;rep(i,n){cout<<p2[i].se<<" ";}}
            else{pno;}
        }
        else{pno;}
        ce;
    
    }
return 0;
}
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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
            v order(n,0);
        rep(i,n)cin>>order[i];
        ll val =order[0];
        v pre,post;
        rep(i,n)pre.pb(order[i]+n-(i+1));
        rep(i,n)post.pb(order[i]+i);
        ll mx = pre[0];
        forf(i,1,n)pre[i]=max(pre[i],pre[i-1]);
        
        forb(i,n-2,0){post[i] =max(post[i],post[i+1]);}
        rep(i,n){
            if(i==0 && i+1<n){val = max(order[i],post[i+1]);}
            else if (i!=n-1){val = min(val,max(max(order[i],pre[i-1]),post[i+1]));}
            else if(i!=0){val = min(val,max(pre[i-1],order[i]));}
        
        }
        cout<<val;ce;
    }
return 0;
}
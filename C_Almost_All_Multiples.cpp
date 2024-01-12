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
        ll n,x;
        cin>>n>>x;
        v perm;
        perm.pb(x);
        forf(i,2,n+1){perm.pb(i);}
        perm[x-1]=n;
        perm[n-1]=1;
        // rep(i,n){cout<<perm[i]<<" ";}ce;
        if(n%x!=0){cout<<-1;ce;}
        else{
            while(1){
            ll index =-1;
            forf(i,x,n-1){if((i+1)%x==0 && n%(i+1)==0){index=i;break;}}
            if(index==-1){break;}
            else{swap(perm[x-1],perm[index]);}
            x = index+1;
            }
            rep(i,n){cout<<perm[i]<<" ";}ce;
        }
    }
return 0;
}
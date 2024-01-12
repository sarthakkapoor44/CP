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
ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {   
        ll a,b;
        cin>>a>>b;
        ll gcd_ = gcd(a,b);
        ll num1 = a/gcd_;
        ll num2 = b/gcd_;
        ll ans = num1*num2*gcd_;
        if(ans ==b){
            ll val  = a;
            ll index=-1;
            if(a==1){ans*=b;}
            else{
                for(int i=2;i*i<=val;i++){
                    if(val%i==0){index=i;break;}
                }
                if(index==-1){index=a;}
                val=b;
                for(ll i=2;i*i<=val;i++){
                    if(val%i==0){index= min(i,index);break;}
                }
                ans*=index;
            }

        }
        cout<<ans;ce;
    }
return 0;
}


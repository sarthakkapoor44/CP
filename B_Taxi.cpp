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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        map<ll,ll> count;
        rep(i,n){count[arr[i]]+=1;}

        // cout<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4];ce;

        ll ans = count[4];
        count[4]=0;

        // cout<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4];ce;

        ans+= min(count[1],count[3]);
        ll val = min(count[1],count[3]);
        count[1]-=val;
        count[3] -=val;

        // cout<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4];ce;

        ans+= count[2]/2;
        count[2]%=2;
        ans+=count[3];
        // cout<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4];ce;
        val = min(count[1]/2,count[2]); 
        count[2] -=val;
        count[1] -=2*val;
        ans+=val;
        ans+=count[1]/4;
        count[1]%=4;
        if(count[1]+count[2])ans++;
        
        cout<<ans;ce;
            }
return 0;
}
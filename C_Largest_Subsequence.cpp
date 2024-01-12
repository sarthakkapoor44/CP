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
        string s;cin>>s;
           ll ans = 0;
        rep(i,n-1){if(s[i+1]-s[i]<0){ans = -1;break;}}
        if(ans==-1){
        v indices;
        forb(j,25,0){
            rep(i,n){
            if(s[i]-'a'==j && (indices.empty()||i>indices.back())){
                indices.pb(i);
            }
            }
        }
        // rep(i,indices.size()){cout<<indices[i]<<" ";}ce;
        ll m =indices.size();
        ll k = 0;
         ans=m-1;
        while(k+1<m && s[indices[k+1]]==s[indices[k]]){k++;ans--;}
        
        rep(i,m/2){swap(s[indices[i]],s[indices[m-i-1]]);}
        // cout<<s;ce;
    
      
    
        rep(i,n-1){if(s[i+1]-s[i]<0){ans = -1;break;}}
        }
        cout<<ans;ce;
    
    }
return 0;
}
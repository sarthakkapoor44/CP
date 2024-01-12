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
        ll n;
        cin>>n;
        string s;cin>>s;
        set<char> c,vo;
        c.insert('b');
        c.insert('c');
        c.insert('d');
        vo.insert('a');
        vo.insert('e');
        ll arr[n+1];
        rep(i,n){
            if(c.count(s[i])==1){arr[i]=1;}else{arr[i]=0;}
        }
        
        arr[n]=1;
        
        // rep(i,n+1)cout<<arr[i]<<" ";ce;
        ll i =0;
        ll sum =0;
        while(i<n+1){
            if(sum==0){if(i!=n){cout<<s[i];}sum+=arr[i];i++;}
            else if(sum==1){
                if(arr[i]==0){cout<<s[i];i++;}
                else{if(i<n && arr[i+1]==1){cout<<s[i];if(i!=n){i++;}}
                     if(i!=n){cout<<".";}
                     sum=0;
                }
            
            }
            
        }
        ce;
    }
return 0;
}
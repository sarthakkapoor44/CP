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
 
    {
        ll n;
        cin>>n;
        for(int i=2;i<=n;i+=2){cout<<i<<" ";}
        v o1,o2;
        if(n%2==1)
        {
            ll i=1;
            while(i<=n)
            {
                if(i<=n)
                {
                    cout<<i<<" ";
                    i+=4;
                }
                else
                {
                    break;
                }
            }
            i=3;
            while(i<=n)
            {
                if(i<=n)
                {
                    cout<<i<<" ";
                     i+=4;
                }
                else
                {
                    break;
                }
            }
           
            
        }
        else{
            if(n>2){
                ll i=3;
                while(i<=n){
                    if(i<=n){
                        
                    cout<<i<<" ";
                    i+=4;
                    }else{break;}
                    }
                    i=1;
                    while(i<=n){
                    if(i<=n){
                       
                    cout<<i<<" ";
                     i+=4;
                    }
                    else{break;}
                }
           
            }
           
        }
        
    }
return 0;
}
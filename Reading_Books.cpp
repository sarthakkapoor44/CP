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
        rep(i,n)cin>>arr[i];
        sort(arr,arr+n);
        ll i =0;
        ll j =n-1;
        ll time =0;
        v copy;
        rep(i,n)copy.pb(arr[i]);
        while(i<j){
            ll val = min(copy[i],copy[j]);
            copy[i]-=val;
            copy[j]-=val;
            if(copy[i]==0 && i!=n-1){i++;}
            if(copy[j]==0 && j!=0){j--;}
            time+=val;
             rep(i,n)cout<<copy[i]<<" "; 
             ce;
            if(i+1==j){break;}
           
        }
        ll val = min(copy[i],copy[j]);
        copy[i]-=val;
        copy[j]-=val;
        time+=val;
        rep(i,n)cout<<copy[i]<<" ";
        ce; 
        ll ans;
        if(copy[j]>0){
            ll right = time- arr[j] +copy[j];
         ans = 2*time + max(arr[j]-time,0ll) + max(copy[j]-right,0ll);
        }
        else{
            ll left = time- arr[i] +copy[i];
         ans = 2*time + max(arr[i]-time,0ll) + max(copy[i]-left,0ll);
        }
        cout<<ans;ce;
    }
return 0;
}
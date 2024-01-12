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
        ll n,x;
        cin>>n>>x;
        vp arr;v arr2;
        rep(i,n){ll num;cin>>num;arr2.pb(num);arr.pb(mp(num,i));}
        srt(arr);
        srt(arr2);
        // rep(i,n)cout<<arr[i].fi<<" ";ce;
        vp sum ;
        rep(i,n){forf(j,i+1,n){if(arr[i].fi+arr[j].fi<x){sum.pb(mp(i,j));}}}
        // rep(i,sum.size()){cout<<sum[i].fi<<" "<<sum[i].se;ce;}
           ll cq=0;
        rep(i,sum.size()){
            ll val = x -arr[sum[i].fi].fi-arr[sum[i].se].fi;
           vector<ll>::iterator itr1,itr2;
            itr1 = lower_bound(arr2.begin(),arr2.end(),val);
            itr2 = upper_bound(arr2.begin(),arr2.end(),val);
            if(itr1==itr2){continue;}
        
            else{
                ll start = itr1-arr2.begin();
                ll end = itr2-arr2.begin();
             
                for(int j=start;j<end;j++){
                    if(j!=sum[i].fi && j!=sum[i].se){cout<<arr[sum[i].fi].se+1<<" "<<arr[sum[i].se].se+1<<" "<<arr[j].se+1;cq=1;break;}
                }
                if(cq){break;}

            }
        }
        if(!cq){cout<<"IMPOSSIBLE";ce;}
    }
return 0;
}
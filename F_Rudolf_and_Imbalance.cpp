///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,m,k;
        cin>>n>>m>>k;
        ll arr[n],d[m],f[k];
        rep(i,n)cin>>arr[i];
        rep(i,m)cin>>d[i];
        rep(i,k)cin>>f[i];
        sort(arr,arr+n);
        sort(d,d+m);
        sort(f,f+k);
        ll left ,right ,diff;
        diff= -INF;
        map<ll,ll> diffs;
        rep(i,n-1){
            diffs[arr[i+1]-arr[i]]++;
            if(arr[i+1]-arr[i]>diff){diff=arr[i+1]-arr[i];left=arr[i];right =arr[i+1];}
        }
        ll diffg  =-INF;
        rep(i,n-1){
            
            if(arr[i+1]-arr[i]>diffg && arr[i+1]-arr[i]!=diff){diffg=arr[i+1]-arr[i];}
        }

        ll ans =diff;
        if(diffs[diff]>1){ans =diff;}
        else {
            ll val1 =(left+right)/2;
            ll val2 =(left+right+1)/2;
            rep(i,m){
                auto x1 = lower_bound(f,f+k,(val1-d[i]))-f;
                auto x2 = lower_bound(f,f+k,(val2-d[i]))-f;
                ll prev1,prev2;
                prev1 =max(x1-1ll,0ll);
                prev2= max(x2-1ll,0ll);
                ll diff1=INF,diff2=INF,diff3=INF,diff4=INF;
                if(x1<k && x1>=0){diff1 = min(max(d[i]+f[x1]-left,right-d[i]-f[x1]),diff);}
                if(x2<k && x2>=0){diff2 = min(diff,max(d[i]+f[x2]-left,right-d[i]-f[x2]));}
                if(prev1<k && prev1>=0)diff3 = min(max(d[i]+f[prev1]-left,right-d[i]-f[prev1]),diff);
                if(prev2<k && prev2>=0)diff4 = min(max(d[i]+f[prev2]-left,right-d[i]-f[prev2]),diff);
                // if(i==4){
                //     cout<<x1<<" "<<x2<<" "<<prev1<<" "<<prev2;
                //     ce;
                //     cout<<diff1<<" "<<diff2<<" "<<diff3<<" "<<diff4;}ce;
                ans =min(ans,diff1);
                ans =min(ans,diff2);
                ans =min(ans,diff3);
                ans =min(ans,diff4);
               
            }
         
           if(diffg>ans)ans=diffg;
        
        }
        cout<<min(ans,diff);ce;
        // rep(i,n)cout<<arr[i]<<" ";ce;
        // rep(i,m)cout<<d[i]<<" ";ce;
        // rep(i,k)cout<<f[i]<<" ";ce;
    }

    return 0;
}

///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(v) sort(v.begin(),v.end())
#define ce cout<<"\n"
#define all(s) s.begin(),s.end()
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i,n) for(ll i=0;i<n;i++)
#define forf(i,a,b) for(ll i=a;i<b;i++)
#define forb(i,a,b) for(ll i=a;i>=b;i--)
#define vp vector<pair<ll,ll>>
#define vll vector<ll>
#define pll pair<ll,ll>
#define OPTIMIZE_IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...) cerr<<"["<<#x<<"] = [";_print(x)
#else
#define debug(x...)
#endif

const ll MODN=1e9+7;
const ll MAXN=1000001;
const ll modn=998244353;

template<typename T>
void out(vector<T>a){
    for(int i=0;i<(int)a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

ll op(ll x,ll y){
    cout<<"? "<<x<<" "<<y<<"\n";
    cout.flush();
    ll res;
    cin>>res;
    return res;
}

int main(){
    OPTIMIZE_IO
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        deque<pair<ll,ll>>sf,sb;

        auto pb_func=[&](ll x)
        {
            if(sb.empty())sb.push_back({x,x});
            else
            {
                ll temp=op(sb.back().se,x);
                sb.push_back({x,temp});
            }
        };

        auto fpop=[&]()->void
        {
            if(sf.empty())
            {
                while(!sb.empty())
                {
                    ll x=sb.back().fi;
                    ll val=sb.back().se;
                    sb.pop_back();
                    if(sf.empty())sf.push_back({x,x});
                    else sf.push_back({x,op(x,sf.back().se)});
                }
            }
            sf.pop_back();
        };

        auto current_window=[&]()->ll
        {
            if(sf.empty()&&sb.empty())return 0;
            else if(sf.empty())return sb.back().se;
            else if(sb.empty())return sf.back().se;
            else return op(sf.back().se,sb.back().se);
        };

        rep(i,k+1)pb_func(arr[i]);
        vll result;
        result.pb(current_window());
        forf(i,k+1,n)
        {
            fpop();
            pb_func(arr[i]);
            result.pb(current_window());
        }
        cout<<"! ";
        out(result);
        cout.flush();
    }
    return 0;
}

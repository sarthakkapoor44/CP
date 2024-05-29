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


ll m,n;
int func( vector<vector<ll> > times,ll mid)
{
    ll sum  =0;
    // cout<<mid<<" ";
    rep(i,n)
    {
        ll ti = times[i][0];
        ll zi = times[i][1];
        ll yi = times[i][2];
        ll val  = zi*((mid)/(ti*zi +yi));
        ll rem =  mid%(ti*zi+yi);
        val +=min(zi,rem/ti);
        sum+= val;

    }
    return sum>=m;
}

v ballons(vector<vector<ll> > times,ll T)
{   v temp;
    rep(i,n)
    {
        ll ti = times[i][0];
        ll zi = times[i][1];
        ll yi = times[i][2];
        ll val  = zi*((T)/(ti*zi +yi));
        ll rem =  T%(ti*zi+yi);
        val +=min(zi,rem/ti);
        temp.pb(val);
    }
    return temp;
}

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    

    {   
        //Lesgooooooo!!!!
        cin>>m>>n;
        vector<vector<ll>  > times;
        rep(i,n)
        {
            v temp(3);
            rep(j,3)cin>>temp[j];
            times.pb(temp);
        } 
        ll right =1e10;
        // while(!func(times,right)){right*=2;}
        ll left  =-1,mid;
        while(right>left+1)
        {
            mid= (left+right)/2;
            if(func(times,mid))right=mid;
            else left=mid;
        }
    
        cout<<right;ce;
        v temp = ballons(times,right);
        ll sum =0;
        for(auto x:temp)
        {
            sum+=x;
        }
        if(sum>m)
        {
            ll ext  = sum-m;
            rep(i,temp.size()){
                ll val = min(temp[i],ext);
                temp[i]-=val;
                ext-=val;
                }
            
        }
        for(auto x:temp){cout<<x<<" ";}
        ce;
        
    }

    return 0;
}

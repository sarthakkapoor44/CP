#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >

int main(){
    ll n,m,l;
    cin>>n>>m>>l;
    vp b;vp a;
    rep(i,n){ll num;cin>>num;a.pb(mp(num,i+1));}
    rep(i,m){ll num; cin>>num;b.pb(mp(num,i+1));}
    srt(b);
    set<pair<ll,ll> > query;
    rep(i,l){ll num1,num2;cin>>num1>>num2;query.insert(mp(num1,num2));}
    // query[-1]=-1;
    ll curr[n];
    rep(i,n){curr[i]= m-1;}
    ll ans =0;
    priority_queue<pair<ll,ll> > pq1;
    // rep(i,m){cout<<b[i].fi<<" ";}ce;
    rep(i,n){pq1.push(mp(a[i].fi+b[curr[i]].fi,i));}

    while(1){
        pair<ll,ll> info = pq1.top();
        ll i = info.se;
        ll cost=info.fi;
        pq1.pop();
        // cout<<i+1<<"  "<<b[curr[i]].se;ce;
        if(query.count(mp(i+1,b[curr[i]].se))==0){ans = cost;break;}
        else{curr[i]-=1;pq1.push(mp(a[i].fi+b[curr[i]].fi,i));}
    }
   

    cout<<ans;

    return 0;
}

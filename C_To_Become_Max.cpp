///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vp vect(n,mp(0,0));
        ll arr[n];
        rep(i,n){cin>>vect[i].fi;arr[i]= vect[i].fi;vect[i].se=-i;}
        sort(all(vect),greater<pair<ll,ll> >());
        rep(i,n){vect[i].se =vect[i].se*=-1;}
        ll ans = vect[0].fi;
        rep(i,n){cout<<arr[i]<<" ";}ce;
        rep(j,n){cout<<vect[j].fi<<"->"<<vect[j].se<<" ";}cout<<k;ce;
        
        ll i=0;
        while(k>0){
        while(1){
               if(i>=n){break;}
            else if(vect[i].se==0)i++;
            else if(vect[i].fi<arr[vect[i].se-1])i++;
           
            else break;
        }
     
        if(i<n && vect[i].se>0 && arr[vect[i].se-1]<=vect[i].fi)
        {
        ll k_copy=k;
        ll val = vect[i].fi;
        if(vect[i].se-2>=0 && arr[vect[i].se-2]>=arr[vect[i].se-1]){val =min(arr[vect[i].se-2],val);}
        k-=min(k,(val-arr[vect[i].se-1]+1));
        arr[vect[i].se-1]+=min(k_copy,(val-arr[vect[i].se-1]+1));
        ans= max( arr[vect[i].se-1],ans);
        rep(j,n){vect[j].fi=arr[j];vect[j].se=-j;}
        sort(all(vect),greater<pair<ll,ll> >());
        rep(j,n){vect[j].se*=-1;}
        rep(j,n){cout<<vect[j].fi<<"->"<<vect[j].se<<" ";}cout<<k;ce;
        }
        else{break;}
        i=0;
        
        }
        cout<<ans;ce;
    }

    return 0;
}


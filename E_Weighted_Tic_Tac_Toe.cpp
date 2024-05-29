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
int check(vector<pair<int,int> > permut)
{   int cq=1;
    vector<vector<ll> > grid(3,vector<ll>(3));
    ll last =0;
    rep(i,9){grid[permut[i].fi][permut[i].se]=last;last=1-last;}
 
    rep(i,3)
    {
        if(grid[i][0]==grid[i][1] && grid[i][1]== grid[i][2])cq=0;
    }
    rep(i,3)
    {
        if(grid[0][i]==grid[1][i] && grid[1][i]== grid[2][i])cq=0;
    }
    if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])cq=0;
    if(grid[2][0]==grid[1][1] && grid[1][1]==grid[0][2])cq=0;
    return cq;
}
vector<vector<pair<int,int> > > all_permut_t,all_permut_a;
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
  
    {   //Lesgooooooo!!!!
        vector<vector<ll> > grid(3,vector<ll>(3));
        rep(i,3)
        {
            rep(j,3)cin>>grid[i][j];
        }
        
        vector<pair<int,int> > permut;
        rep(i,3)
        {
            rep(j,3){permut.pb(mp(i,j));}
        }
        
        ll all_comb  =362880 ;
        ll t=0;
        ll a =0;
        rep(i,all_comb)
        {
          next_permutation(all(permut));
          if(check(permut))
          {
            ll last =0;
            ll tscore=0,ascore=0;
            rep(j,9)
            {
                
                if(last==0)tscore+=grid[permut[j].fi][permut[j].se];
                else ascore+=grid[permut[j].fi][permut[j].se];
                last=1-last;
            }
            if(tscore>ascore){
                all_permut_t.pb(permut);

            }
            else  all_permut_a.pb(permut);
          
          }

        }
        ll cq=1;
        rep(j,9){
        set<pair<int,int> >  pos_t,pos_a;
        rep(i,all_permut_t.size())
        {
            pair<int,int> val = all_permut_t[i][j];
            pos_t.insert(val);
        }

        rep(i,all_permut_a.size())
        {
          if(pos_t.count(all_permut_a[i][j])) pos_a.insert(all_permut_a[i][j]);
          
        }
        if(pos_a.size()==0){cq=0;break;}
        }
       if(cq)cout<<"Aoki";
       else cout<<"Takahashi";ce;
        
    }

    return 0;
}

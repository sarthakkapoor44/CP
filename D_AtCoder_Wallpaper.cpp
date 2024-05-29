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
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll width = c-a;
        ll height = d-b;      
        ll left_horz = (width)%4;
        ll ans = ((width)/4)*(height/2)*8;
        if((height%2))ans+= (width/4)*2;
        a = a%4;
        a=(a+4)%4;
        b = b%2;
        b= (b+2)%2;
        ll wid_left= 0;
        ll ht_left=0;
        if(left_horz==1)
        {
            if(a==0 || a==1){wid_left = 3;}
            if(a==2 || a==3){wid_left =1;}
           if(!(b%2))
           { 
            if(a==0)ht_left=2;
            if(a==1 || a==3)ht_left=1;
           }
            else
            {
                if(a==0||a==2)ht_left=1;
                if(a==1)ht_left=2;
                if(a==3)ht_left=0;
            }
        }
        if(left_horz==2)
        {
            if(a==0)wid_left=6;
            if(a==1 || a==3) wid_left=4;
            if(a==2)wid_left=2;
           if(!(b%2)){ if(a==0 || a==3)ht_left=3;
            if(a==1|| a==2)ht_left=1;}
            else
            {
                    if(a==0 || a==1)ht_left=3;
                if(a==2 || a==3)ht_left=1;
            }
        }
        if(left_horz ==3)
        {
            if(a==0 || a==3)wid_left=7;
            if(a==1 || a==2)wid_left=5;
           if(!(b%2)){ if(a==0 || a==2)ht_left =3;
            if(a==1)ht_left=2;
            if(a==3)ht_left=4;}
            else 
            {
                if(a==0)ht_left=4;
                if(a==1|| a==3)ht_left=3;
                if(a==2)ht_left=2;
            }
        }
        ans+= (height/2)*wid_left;
        if((height%2))
        {
            ans+=ht_left;
        }
        cout<<ans;ce;
    }

    return 0;
}

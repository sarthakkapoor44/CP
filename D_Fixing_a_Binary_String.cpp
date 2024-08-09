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
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll pos  =-1;
        char prev = '-';
        int cq=0;
        for(int j=0;j<n/k;j++)
        {
            char start = s[j*k];
            if(prev==start){pos = j*k;cq=2;break;}
            prev =start;
            forf(i,1,k)
            {   
                if(start!=s[i+j*k]){pos = i+j*k;cq=1;break;}
            }
            if(cq)break;
        }
        int cnt=  0;
        string fin ="";
        bool flag=1;
        if(cq==1)
        {
            rep(i,pos)fin+=s[i];
            forb(i,n-1,pos){fin+=s[i];}
        }
        else if (cq==2)
        {
            
            cnt  =0;
            forb(i,n-1,0)
            {
                if(s[i]==s[pos])
                {
                    cnt++;
                }
                else{break;}
            }
           
            if(cnt>=k)flag=0;
            else
            {
                forf(i,0,pos-cnt){fin+=s[i];}
                forb(i,n-1,pos-cnt){fin+=s[i];}
            }
        }
        else if (cq==0){fin=s;}
    
        
        prev ='-';
    
        for(int j=0;j<n/k;j++)
        {
            char start = fin[j*k];
            if(prev==start){flag=0;break;}
            prev =start;
            forf(i,1,k)
            {   
                if(start!=fin[i+j*k]){flag=0;break;}
            }
            
        }
        if(flag && cq==1){cout<<pos;}
        else if(flag && cq==2){cout<<pos-cnt;}
        else if(flag && !cq){cout<<n;}
        else cout<<-1;
        ce;
    }

    return 0;
}

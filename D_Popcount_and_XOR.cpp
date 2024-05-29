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
        ll a,b;
        unsigned long long c;
        cin>>a>>b>>c;
        bitset<60> x = c;
        ll pc_c=0;
        rep(i,60)if(x[i]== 1)pc_c++;
        ll left = 60-pc_c;
        ll a_cnt=-INF,b_cnt=-INF;

        rep(i,pc_c+1)
        {
            ll l = a-i;
            ll r = b - (pc_c-i);
            if(l>=0 && r>=0  && r==l)
            {
                if(l+r<=(left)*2)
                {
                    a_cnt = i;
                    b_cnt = pc_c-i;
                    break;
                }
            }
        }
        ll cq=1;
        if(a_cnt==-INF || b_cnt==-INF )cq=0;
        // cout<<a_cnt<<" "<<b_cnt;
        if(cq)
        { 
        bitset<60> A =c ;
        bitset<60> B  ;
        ll cnt  =0;
        ll cq2=1;
        if(!(a_cnt))cq2=0;
        rep(i,60)
        {
            if(cnt>=a_cnt)cq2=0;
            if(!cq2)A[i]=0;
            if(A[i]==1)cnt++;
            
        }
        B  = A^x;
        ll rem = a-a_cnt;
        rep(i,60)
        {
            if(!A[i] && !B[i])
            {
                if(rem){A[i]=1;B[i]=1;rem--;}
            }
        }
        if(rem)cq=0;

        if(cq){
        unsigned long long a1  = A.to_ulong();
        unsigned long long b1  = B.to_ulong();
        cout<<a1<<" "<<b1;ce;
        }
        else cout<<-1;
        
        }
        else cout<<-1;
        
        ce;

    }

    return 0;
}

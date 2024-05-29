///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
// typedef long long unsigned long long;
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
#define rep(i, n) for (unsigned long long i = 0; i < n; i++)
#define forf(i, a, b) for (unsigned long long i = a; i < b; i++)
#define forb(i, s, e) for ( long long i = s; i >= e; i--)
#define vp vector<pair<unsigned long long, unsigned long long> >
#define v vector<unsigned long long>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const unsigned long long MODN = 1e9 + 7;
const unsigned long long MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// unsigned long long gcd(unsigned long long a, unsigned long long b);

int main() {
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        unsigned long long a,b,r;
        cin>>a>>b>>r;
        if(b>a){swap(a,b);}
    
        bitset<65> bits1(a);
        bitset<65> bits2(b);
        bitset<65> bits3(r);
        bitset<65> bits4(0);
        // cout<<"A";ce;
        //     rep(i,64){
        //     cout<<bits1[i]<<" ";
        // }
        // ce;
        // cout<<"B";ce;
        //     rep(i,64){
        //     cout<<bits2[i]<<" ";
        // }ce;
        // cout<<"R";ce;
        //     rep(i,64){
        //     cout<<bits3[i]<<" ";
        // }ce;
        unsigned long long first_diff_bit= 0;
        forb(i,59,0){
            if(bits1[i]!=bits2[i] && bits1[i]==1){
                if(!first_diff_bit)first_diff_bit=1;
                else{
                    bits4[i]=1;
                }
            }
        }
        //  cout<<"X";ce;
        //     rep(i,64){
        //     cout<<bits4[i]<<" ";
        // }ce;
        unsigned long long first_bit_r=0;
        long long msb_4=0;
        forb(i,59,0){
           if(bits3[i]==1){first_bit_r=1;}
           if(!msb_4 && bits4[i]==1){msb_4=i;}
           if(!first_bit_r && bits4[i]==1 && bits3[i]==0){bits4[i]=0;}

        }
        if(bits4.to_ullong()>r){
            forb(i,msb_4-1,0){
                if(bits3[i]==1 && bits4[i]==0){break;}
            bits4[i] = (bits4[i]&bits3[i]);
            }
        }
        //  cout<<"X_n";ce;
        //     rep(i,64){
        //     cout<<bits4[i]<<" ";
        // }
        //   rep(i,40){
        //     cout<<bits1[i]<<" ";
        // }
      
        unsigned long long val1=0,val2=0;

          rep(i,60){
            bits1[i]= (bits4[i]^bits1[i]);
            bits2[i] = (bits4[i]^bits2[i]);
        }
      
        rep(i,60){
        val1+= (1ll<<i)*(bits1[i]);
        val2+= (1ll<<i)*(bits2[i]);
        }
        cout<<abs((long  long)val1-(long long)val2);ce;
    }

    return 0;
}

//-----Smallest prime factor----------//
/*
void sieve() {
for (int i = 1; i < MAXN; i++)
    spf[i] = i;
 for (int i = 2; i <  MAXN; i++) {
if (spf[i] != i)
    continue;
for (int d = 2 * i; d < MAXN; d += i)
spf[d] = min(spf[d], i);
}
}
*/


//-----GCD----------//
/*
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}
*/

//-----Sieve of eratosthenes----------//
/*
void sieve_of_eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (unsigned long long i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (unsigned long long j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
*/
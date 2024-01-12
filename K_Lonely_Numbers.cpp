////////// DYNATOS //////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout << endl
#define all(s) s.begin(), s.end()
#define pyes cout << "YES";
#define pno cout << "NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
int is_prime[MAXN];
int spf[MAXN];

// Function declarations
// void sieve();
// void sieve_of_eratosthenes();
ll gcd(ll a, ll b);
ll arr[MAXN];
int main() {
    // Optimize input/output
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
     is_prime[0] = is_prime[1] = 1;

    for (ll i = 2; i < MAXN; i++) {
        if (!is_prime[i] && (long long)i * i < MAXN) {
            for (ll j = i * i; j < MAXN; j += i) {
                is_prime[j] = 1;
            }
       
        }
         arr[i] = arr[i-1] + 1-is_prime[i];
    }
   int t,n;
 scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int x=sqrt(n);
		printf("%d\n",arr[n]-arr[x]+1);
	}

    return 0;
}


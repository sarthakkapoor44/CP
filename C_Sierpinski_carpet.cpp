
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

void createCarpet(int k, vector<vector<char>>& carpet, int x, int y, int size) {
if (k == 0) {
carpet[x][y] = '#';  
} else {
ll len = size / 3;
rep(i,3) {
rep(j,3) {
if (i == 1 && j == 1) {

rep(dx,len) {
rep(dy,len) {
carpet[x + dx + len][y + dy + len] = '.';
}}
} else {
createCarpet(k - 1, carpet, x + i * len, y + j * len, len);
}}}}}



void printCarpet(const vector<vector<char>>& carpet) {
    for (const auto& row : carpet) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {   //Lesgooooooo!!!!
        ll N;

        cin >> N;

        ll size = 1;
        for (ll i = 0; i < N; ++i) {
            size *= 3;
        }

        vector<vector<char>> carpet(size, vector<char>(size, '#'));
        

        createCarpet(N, carpet, 0, 0, size);

        printCarpet(carpet);

        return 0;
    }

    return 0;
}
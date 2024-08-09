///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC final("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
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
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

ll solve(string a, string final, ll n) {
    a+= "..";
    queue<pair<string, ll>> q;
    set<string> vis;
    q.push({a, 0});vis.insert(a);
    while (!q.empty()) 
    {
        auto [val, nums] = q.front();
        q.pop();if (val.substr(0, n) == final) {return nums;}
        rep(i,n+1){if (val[i] != '.' && val[i + 1] != '.') {string temp = val;rep(k,n+2) {if (temp[k] == '.' && temp[k + 1] == '.') {temp[k] = val[i];temp[k + 1] = val[i + 1];temp[i] = '.';temp[i + 1] = '.';
        if (vis.find(temp) == vis.end()){vis.insert(temp);q.push({temp, nums + 1});}temp[k] = '.';temp[k + 1] = '.';temp[i] = val[i];temp[i + 1] = val[i + 1];}}}}
    }
    return -1;
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n;
        string s, t;
        cin>>n>>s>>t;
        cout<< solve(s,t, n);
    }

    return 0;
}


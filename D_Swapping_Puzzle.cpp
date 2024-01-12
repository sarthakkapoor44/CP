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
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    
        ll row,col;
        cin>>row>>col;
        v temp (col,0);
        vector<vector<ll> > a,b; 
        vector<vector<ll> > a_copy,b_copy; 
        rep(i,row){
        v column;
        rep(j,col){ll a;cin>>a;column.pb(a);}
        
        //  srt(column);
        a.pb(column);

        }
        // srt(a);
        // rep(i,row){rep(j,col){cout<<a[i][j]<<" ";}ce;}
        rep(i,row){
        v column;
        rep(j,col){ll a;cin>>a;column.pb(a);}
        
        //  srt(column);
        b.pb(column);

        }
        // srt(b);
        // ll ans=0;
        // rep(i,row){rep(j,col){if(a[i][j]!=b[i][j]){ans=0;break;}}}
    a_copy= a;
    b_copy=b;
    rep(i,row){
        srt(a_copy[i]);
        srt(b_copy[i]);
    }
    v v1,v2;
    rep(i,row){rep(j,row){
        if(a_copy[i]==b_copy[j]){v1= a[i];v2 =b[j];break;}
    }
    }
     ll moves1=0;
    // rep(i,v1.size()){cout<<v1[i]<<" ";}ce;
    // rep(i,v2.size()){cout<<v2[i]<<" ";}ce;ce;
    rep(i,v1.size()){
    if(v1[i]!=v2[i]){
        forf(j,i+1,v2.size()){
        if(v2[j]==v1[i])
        {ll temp =v1[i];
        v1[i] = v2[j];
    v2[j] =temp;
    // cout<<i<<" "<<j;ce;
    
            moves1+=abs(i-j) + abs(i-j)-1;break;}
        }
        
    }
    // rep(k,v1.size()){cout<<v1[k]<<" ";}ce;
    // rep(k,v2.size()){cout<<v2[k]<<" ";}ce;ce;
    }
   
    v v3,v4;
    rep(i,row){
        v3.pb(a_copy[i][0]);
        v4.pb(b_copy[i][0]);
    }
    rep(i,v3.size()){
    if(v3[i]!=v4[i]){
        forf(j,i+1,v4.size()){
        if(v4[j]==v3[i])
        {ll temp =v3[i];
        v3[i] = v4[j];
    v4[j] =temp;
    // cout<<i<<" "<<j;ce;
            moves1+=abs(i-j)+abs(i-j)-1;break;}
        }
        
    }
    }
    srt(a_copy);srt(b_copy);
    rep(i,row){rep(j,col){if(a_copy[i][j]!=b_copy[i][j]){moves1=-1;break;}}}
     cout<<moves1;ce;
return 0;
}
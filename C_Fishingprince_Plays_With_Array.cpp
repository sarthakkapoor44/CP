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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
int main(){int t;cin>>t;while(t--){ll n,m,k;cin>>n>>m;ll A[n];rep(i,n){cin>>A[i];}cin>>k;ll B[k];rep(i,k){cin>>B[i];}
    vp vect1,vect2;ll i=0;//cout<<n<<m<<k;
    while(i<n){
        ll count=0;
        if(A[i]%m==0){
            ll num;
        while(i<n && A[i]%m==0 ){while(1){if(A[i]%m!=0){break;}else{A[i]=A[i]/m;count+=1;}num=A[i];count =pow(num,count);};i++;}
        vect1.pb(mp(num,count));
        }
        else{vect1.pb(mp(A[i],1));i++;}
    }
    i=0;
     while(i<k){
        ll count=0;
        if(B[i]%m==0){
        while(i<k && B[i]%m==0 ){count+=B[i];i++;}
        vect2.pb(mp(1,count));
        }
        else{vect2.pb(mp(B[i],1));i++;}
    }
    ll cq=1;
    rep(j,vect1.size()){cout<<"("<<vect1[j].fi<<","<<vect1[j].se<<") ";}ce;
    rep(j,vect2.size()){cout<<"("<<vect2[j].fi<<","<<vect2[j].se<<") ";}ce;ce;
    if(vect1.size()!=vect2.size()){cq=0;}
    else{rep(j,vect1.size()){if(vect1[j]!=vect2[j]){cq=0;break;}}}
    //if(cq){cout<<"Yes";}else{cout<<"No";}ce;
    }
    return 0;
}
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define forf for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define vp vector<pair<long long, long long> >
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n,m,d;
     cin>>n>>m>>d;
     unordered_map<ll,ll> ip;
    forf{ll a; cin>>a;ip[a]=i+1;}
    ll arr[m],index[m];
    for(int i=0;i<m;i++){cin>>arr[i];index[i]=ip[arr[i]];}
    //for(int i=0;i<m;i++){cout<<index[i]<<" ";}
    ll min_=INT_MAX;
    ll max_= INT_MIN;
    for(int i=0;i<m-1;i++){min_ = min(index[i+1]-index[i],min_);
    if((index[i+1]-index[i])>max_ && n-index[i+1]+index[i]-1>=d+1-index[i+1]+index[i]){max_ = index[i+1]-index[i];}
    }
    ll max_shift = d+1-max_;
    if(min_<0 || max_shift<0){cout<<0;}
    else{
    cout<< min(max_shift,min_);
    }
    cout<<endl;
    }
    return 0;
}
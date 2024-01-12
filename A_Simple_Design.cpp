#include<bits/stdc++.h>
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
ll calc_sum(ll x){
    ll sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
     ll x,k;
     cin>>x>>k;
     ll sum = calc_sum(x);
     ll ans=x;
     if(sum%k!=0){
        for(int i =1;i<=9;i++){
            if(calc_sum(x+i)%k==0){ans =x+i;break;}
        }
        if(ans==x){
            x+=9;
           
        for(int i =1;i<=9;i++){
    
            if(calc_sum(x+i)%k==0){ans =x+i;break;}
        }
        }
     }
cout<<ans<<endl;
    }
    return 0;
}
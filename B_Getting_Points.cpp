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
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n,p,l,t;
     cin>>n>>p>>l>>t;
     ll sum=0;
     
     ll j=n;
     while((j-1)%7!=0){j--;}
     ll pt = (j-1)/7+1;
    //  cout<<pt;ce;
     
     ll single = pt%2;
     ll dub = pt/2;
    //  cout<<single<<" "<<dub<<" ";
     if(dub> 0 && p/((2*t+l)*dub)==0){
        
        sum+= (p/(2*t+l));
        
        if((p%(2*t+l))!=0){sum+=1;}
        }
     else{
        p -= dub*(2*t+l);
        sum+= dub;

        if(p/((t+l))==0 and single>0){sum+=1;}
        else{
            p-=single*(t+l);
            sum+=single;
            sum+=p/l;
            if(p%l!=0 && p>0){sum++;}
        }
     }
     cout<<n-sum;ce;
    }
    return 0;
}
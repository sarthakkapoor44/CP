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
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n0,n1,n2;
     cin>>n0>>n1>>n2;
     if(n1==0){
        if(n2){for(int i=0;i<=n2;i++){cout<<1;}}
        else{for(int i=0;i<=n0;i++){cout<<0;}}
     }
    else{
      
        if(n1%2==0){
            
            while(n0--){
               cout<<'0';
            }
            
            n1/=2;
            
              cout<<'0';
              n2++;
                while(n2--){cout<<'1';}
                
            n1--;
            while (n1--)
            { cout<<"01";
            }
            
            cout<<0;
           
        }
        else{
            while(n2--){cout<<'1';}
            n1++;
            n1/=2;
            while(n1--){cout<<"10";}
            while(n0--){cout<<'0';}
        }
        
    }
  
    cout<<endl;
    }
    return 0;
}
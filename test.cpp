#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000001
#define mod 1000000007
void solve()
{
    ll n; 
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) 
    {
        cin>>arr[i];
    }
    vector<ll> vect[21];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=20;j++)
        {
            if(arr[i]&(1<<j)) vect[j].push_back(i+1);
        }
    }
    ll q; cin>>q;
    while(q--){
        ll ans = MAXN, val2 = -1, val3 = MAXN;
        ll index, temp; 
        cin>>index;
        cin>>temp;
        for(ll i = 20; i>=0; i--){
            if (vect[i].size() == 0) continue;
            auto x = lower_bound((vect[i]).begin(), (vect[i]).end(), index);
            if ( temp < (1<<i) && val2 == -1 ){
                auto x = lower_bound((vect[i]).begin(), (vect[i]).end(), index);
                if ( x != (vect[i]).end() ){
                    ans = min(ans, *x);
                }
            }
            else if (temp < (1<<i)){
                auto x = lower_bound((vect[i]).begin(), (vect[i]).end(), index);
                if ( x != (vect[i]).end() ){
                    if (val3 == MAXN){
                    val3 = min(val3, *x);
                    val3 = max(val2,val3);
                    }
                    else{
                        ll  newans = min(val3, *x);
                        newans = max(val2,newans);
                        val3 = min(val3, newans);
                    }
                }
               
            }
            else{
                auto x = lower_bound((vect[i]).begin(), (vect[i]).end(), index);
                if ( x != (vect[i]).end() ){
                    val2 = max(val2, *x);
                  
                    temp -= (1<<i);
                }
   
            }
        }
        if ( temp > 0){val2 = -1;}
        if ( val2 > 0){
            cout<<min(min(ans,val2),val3)<<" ";
        }
        else if (min(ans,val3) == 1e6){
            cout<<-1<<" ";
        }
        else{
            cout<<min(ans,val3)<<" ";
        }
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
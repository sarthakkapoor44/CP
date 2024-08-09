#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<ll> a = {0},b = {0};

    ll tot1 = 0,tot2 =0 ;
    for(int i=n-1;i>=0;i--){
        if(tot1>tot2){tot2+= arr[i];b.push_back(tot2);}
        else {tot1+=arr[i];a.push_back(tot1);}
    }
    ll ans = tot1+tot2;
    ll left =  abs(tot1-tot2);
    if(tot1>tot2)
    {
        if(left> a[a.size()-2])ans+=left  -a[a.size()-2];
    }
    else{
        if(left> b[b.size()-2])ans+=left  -b[b.size()-2];
    }
    cout<<ans;
}
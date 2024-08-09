#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll tot =0;
    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        tot+= b;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    ll val =0,sum =0;
    for(int i=0;i<n;i++){
        sum+= arr[i];
        val+=sum;
    }
    cout<<tot-val;
}
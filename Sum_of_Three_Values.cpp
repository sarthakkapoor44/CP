#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000ll
int main(){
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i].first;arr[i].second= i;}
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++){
            ll left =x - arr[i].first- arr[j].first;
            if(left>0)
            {
                auto y = lower_bound(arr.begin(),arr.begin()+j,make_pair(left,-INF))-arr.begin();
                if(y<n && arr[y].first == left && y!=j && y!=i)
                {
                    cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[y].second+1;
                    return 0;
                    }
            }
        }
    }
    cout<<"IMPOSSIBLE";

}
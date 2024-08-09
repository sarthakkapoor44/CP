#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    set<ll> st;
    st.insert(arr[0]);
    for(int i=1;i<n;i++)
    {
        auto x = st.lower_bound(arr[i]);
        if(x == st.begin())st.insert(arr[i]);
        else
        {
            x--;
            st.erase(x);
            st.insert(arr[i]);
        }
    }
    cout<<st.size();
}
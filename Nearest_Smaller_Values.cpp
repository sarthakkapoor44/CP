#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    stack<ll> st;
    st.push(0);
    vector<ll> ans = {0};
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())ans.push_back(0);
        else ans.push_back(st.top()+1);
        st.push(i);
    }
    for(auto x: ans)cout<<x<<" ";
}
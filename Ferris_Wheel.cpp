#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int st =0,end =n-1;
    int cnt=0;
    while(st<=end)
    {
        if(arr[st] +arr[end]<= x){cnt++;st++;end--;}
        else{
            cnt+=1;
            end--;
        }
    }
    cout<<cnt;
}
#include<iostream>
using namespace std;
int gen_sub(int arr[],int n,vector<int> v,int l,int sum,int count){
if(l>=n){
if(count==sum){return 1;}
return 0;
}
v.push_back(arr[l]);
count+=arr[l];
l++;
int left = gen_sub(arr,n,v,l,sum,count);
v.pop_back();
count-=arr[l-1];
int right  =gen_sub(arr,n,v,l,sum,count);
return right+left;
}
int main(){
    int arr[]={3,1,2,5,4,6,0};
    int n=7 ;
    int sum  = 5;
    vector<int> v;

    cout<<gen_sub(arr,n,v,0,sum,0);
   
    return 0;
}
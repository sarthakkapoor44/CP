#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int i=1;i<=t;i++){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=0,y=0;
    for(int j=0;j<s.length();j++){
        if(s[j]=='A'){
           x=j;
            break;
        }
    }
for(int j=s.length()-1;j>=0;j--){
    if(s[j]=='B'){
        y=j;
        break;
    }
}
if(y>x && x>=0 && y>0 && y!=n){
    cout<<y-x<<endl;
}
else{
    cout<<0<<endl;
}
}
return 0;
}
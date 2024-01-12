#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    string name;
    cin>>name;
    if(name.length() < 10){
        cout<<name<<endl;
    }
     else{
        string nam;
        int l=name.length();
        nam+=name[0];
        nam+=to_string(l-2);
        nam+=name[l-2];
        
      cout<<nam;
     }
}


return 0;
}
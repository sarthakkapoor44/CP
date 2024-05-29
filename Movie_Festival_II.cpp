#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll a,b,k;
	    cin>>a>>b>>k;
	    ll num=a;
	    int cnt  =0;
	    while(num<=b)
	    {
	        num*=k;
	        cnt++;
	    }
	   if(num!=b)
       { 
        num/=k;
	    cnt--;
        }
	    ll ans =0;
	    ll diff =b-num;
	    ll cnt2=0;
      
	    while(1)
	    {
    	    if(diff)
    	    {
        	    while(!(diff%k))
        	    {
        	     
        	        diff/=k;
        	        cnt2++;
        	    }
        	    if(cnt>=cnt2)
        	    {
        	        ans+= cnt2+diff%k;
        	        cnt-=cnt2;
                    diff-=diff%k;
                    cnt2=0;
        	    }
        	    else
        	    {
        	        ans+= cnt+ pow(k,cnt2-cnt)*diff;
        	        cnt=0;
        	        diff=0;
        	    }    
            }
	        else break;
	    }
	    cout<<ans+cnt<<endl;
	}
}

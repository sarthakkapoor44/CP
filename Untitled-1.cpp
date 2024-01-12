
       #include<bits/stdc++.h>
       using namespace std;
       typedef long long ll;
       #define fi first
       #define v vector<long long>
       #define se second
       #define srt(vect) sort(vect.begin(),vect.end())
       #define ce cout << endl 
       #define pb push_back
       #define mp make_pair
       #define rep(i, n) for (ll i = 0; i < n; i++)
       #define forf(i, a, b) for (ll i = a; i < b; i++)
       #define forb(i, s, e) for (ll i = s; i >= e; i--)
       #define vp vector<pair<long long, long long> >
       int main(){
        int numRows;
        cin>>numRows;
        vector<vector<int> >ans;
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(1);
        temp.push_back(0);
        ans.push_back(temp);
       vector<int> final;
        for(int i =1;i<numRows;i++){
           final.clear();
           final.pb(0);
          for(int j=0;j<(ans[i-1].size()-1);j++){
            ll val= ans[i-1][j]+ans[i-1][j+1];
                final.push_back(val);
            }
            final.pb(0);
         ans.push_back(final);   
        }
        cout<<ans.size();ce;
        rep(i,numRows+1){
            rep(j,ans[i].size())cout<<ans[i][j];ce;
        }
       }
        
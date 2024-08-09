///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        v pro(n+m+1),test(n+m+1);
        rep(i,n+m+1)cin>>pro[i]; 
        rep(i,n+m+1)cin>>test[i];
        set<ll> pro_taken,test_taken;
        ll pro_sum=0,test_sum=0;
        v ans;
        // vector<ll> pro_size(n+m,0),test_size(n+m,0);
        set<ll> pro_inverse,test_inverse;
        rep(i,m+n)
        {
            if((pro[i]>test[i] && pro_taken.size()<n) || test_taken.size()==m)
            {
                pro_taken.insert(i);
                pro_sum+=pro[i];
               if(pro[i]<test[i]){test_inverse.insert(i);}
            }
            else
            {
                test_taken.insert(i);
                test_sum+=test[i];
                if(pro[i]>test[i]){pro_inverse.insert(i);}
            }
           
        }
        ans.pb(pro_sum+test_sum);
        ll old  =n+m-1;
        ll latest = n+m;
        ll sum =pro_sum+test_sum;
        while(old>=0)
        {
           if((pro_taken.count(old) && pro[old]>test[old] &&  pro[latest]>test[latest]) || (test_taken.count(old)&&  pro[old]<test[old]  && pro[latest]<test[latest]) )
           {
                if(pro[latest]>test[latest])
                {
                    sum+= (pro[latest]-pro[old]);
                    pro_taken.erase(old);
                    pro_taken.insert(latest);
                }
                else {
                    sum+= (test[latest]-test[old]);
                    test_taken.erase(old);
                    test_taken.insert(latest);
                }
           }
           else if( (pro_taken.count(old) && pro[old]<test[old]) || (test_taken.count(old) && pro[old]>test[old]))
           {
                if(pro_taken.count(old))
                {
                    sum+= (pro[latest]-pro[old]);
                    pro_taken.erase(old);
                    pro_taken.insert(latest);
                    test_inverse.erase(old);
                    if(pro[latest]<test[latest])test_inverse.insert(latest);
                }
                else
                {
                    sum+= (test[latest]-test[old]);
                    test_taken.erase(old);
                    test_taken.insert(latest);
                    pro_inverse.erase(old);
                    if(pro[latest]>test[latest])pro_inverse.insert(latest);
                }
           }
           else if(( pro_taken.count(old) && pro[old]>test[old] && pro[latest]<test[latest]) || (test_taken.count(old)&&  pro[old]<test[old]  && pro[latest]>test[latest]) )
           {
                
                if(pro[latest] <test[latest])
                {
                    ll last;
                    if(test_taken.size()>0)last = *(--test_taken.end());
                    if(test_taken.size()==0 || last<latest)
                    {
                        sum+= (pro[latest]-pro[old]);
                        pro_taken.erase(old);
                        pro_taken.insert(latest);
                        test_inverse.insert(latest);
                    }
                    else
                    {
                        pro_taken.erase(old);
                        test_taken.insert(latest);
                        auto x =pro_inverse.lower_bound(latest);
                        if(x!=pro_inverse.end())
                        {
                            sum+= (pro[*x]-pro[old]+test[latest]-test[*x]);
                            pro_taken.insert(*x);
                            test_taken.erase(*x);
                            pro_inverse.erase(x);
                        }
                        else 
                        {
                            test_taken.erase(last);
                            pro_taken.insert(last);
                            test_inverse.insert(last);
                            sum+=(-pro[old]+pro[last]+test[latest]-test[last]);
                        }
                    }
                }
                else if(pro[latest] >test[latest])
                {
                    ll last;
                    if(pro_taken.size()>0)last = *(--pro_taken.end());
                    if( pro_taken.size()==0 ||last<latest )
                    {
                        sum+= (test[latest]-test[old]);
                        test_taken.erase(old);
                        test_taken.insert(latest);
                        pro_inverse.insert(latest);
                    }
                    else
                    {
                        test_taken.erase(old);
                        pro_taken.insert(latest);
                        auto x =test_inverse.lower_bound(latest);
                        if(x!=test_inverse.end())
                        {
                            sum+= (test[*x]-test[old]+pro[latest]-pro[*x]);
                            test_taken.insert(*x);
                            pro_taken.erase(*x);
                            test_inverse.erase(x);
                        }
                        else 
                        {
                            pro_taken.erase(last);
                            test_taken.insert(last);
                            pro_inverse.insert(last);
                            sum+=(-test[old]+test[last]+pro[latest]-pro[last]);
                        }
                    }
                }

           }
            ans.pb(sum);
            old--;
            latest--;
        }
        reverse(all(ans));
        rep(i,ans.size())cout<<ans[i]<<" ";ce;
    }

    return 0;
}

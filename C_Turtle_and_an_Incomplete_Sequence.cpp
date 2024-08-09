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

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n);
        v ans(n);
        rep(i,n)
        {   
            cin>>arr[i];
            if(arr[i]!=-1)ans[i] =arr[i];
        }
        bool cq=1;
        rep(p,n)
        {
            if(arr[p]==-1)
            {
                ll start=p-1;
                while(p<n && arr[p]==-1)p++;
                ll end = p;
                if(start>=0 && end<n)
                {
                    ll mn = min(arr[end],arr[start]);
                    ll mx  =max(arr[end],arr[start]);
                    bitset<32> min = mn;
                    bitset<32> max = mx;
                    bool flag=0;
                    ll removed =0;
                    ll mn_bits =0;
                    ll mx_bits=0;
                    forb(i,31,0)
                    {
                        if(max[i] )
                        {
                            mx_bits=i+1;
                            break;
                        }

                    }
                    ll j =mx_bits-1;
                    forb(i,31,0)
                    {
                        if(min[i] || flag)
                        {   
                            if(!flag)mn_bits=i+1;
                            if(min[i]!=max[j]){removed = i+1;break;}
                            flag=1;
                            j--;
                        }

                    }

                    ll moves = mx_bits+2*removed-mn_bits;
                    ll left_moves  = end-start;
                    if(!(moves<= left_moves && moves%2== left_moves%2)){
                       cq=0;break;
                    }

                    if(arr[start]==mn)
                    {
                        forf(i,start+1,start+removed+1)
                        {
                          ans[i]=  ans[i-1]/2;
                        }
                        
                        ll k =start+removed+1;
                        forb(i,mx_bits-mn_bits+removed-1,0)
                        {
                            if(max[i]==1){ans[k]=ans[k-1]*2+1;}
                            else ans[k] =ans[k-1]*2;
                            k++;
                        }
                        forf(i,k,end)
                        {
                            ans[i]=ans[i-1]*2;
                            if(i+1<end)ans[i+1]=ans[i]/2;
                            i++;
                        }
                        // forf(i,k,end){ans[i]=ans[i-1]/2;if(i+1<end)ans[i+1]=ans[i]*2;}
                    }
                    else
                    {
                        forb(i,end-1,end-removed)
                        {
                          ans[i]=  ans[i+1]/2;
                        }
                        ll k =end-removed-1;
                    
                        forb(i,mx_bits-mn_bits+removed-1,0)
                        {
                            if(max[i]==1){ans[k]=ans[k+1]*2+1;}
                            else ans[k] =ans[k+1]*2;
                            k--;
                        }
                        forb(i,k,start)
                        {
                            ans[i]=ans[i+1]*2;
                            if(i-1>start)ans[i-1]=ans[i]/2;
                            i--;
                        }
                        // cout<<k<<endl;
                        // forb(i,k,start+1){ans[i]=ans[i+1]/2;if(i-1>start)ans[i-1]=ans[i]*2;}
                    }
                    // cout<<removed<<" "<<mx_bits<<" "<<mn_bits;ce;
                   
                }
                else if(start==-1 && end  == n)
                {
                    rep(i,n)
                    {
                        ans[i]=1;
                        if(i+1<n)ans[i+1]=2;
                        i++;
                    }
                }
                else if(start==-1)
                {
                   
                    
                        forb(i,end-1,0)
                        {
                           if(ans[end]!=1)
                            {
                                ans[i] =ans[i+1]/2;
                                if(i-1>=0)ans[i-1] =ans[i]*2;
                            }
                            else
                            {
                                ans[i] =ans[i+1]*2;
                                if(i-1>=0)ans[i-1] =ans[i]/2;
                            }
                            i--;
                        }
                        
                }
                else if(end==n) 
                {
                        forf(i,start+1,n)
                        {
                           if(ans[start]!=1) 
                            {    
                                ans[i] =ans[i-1]/2;
                                if(i+1<n)ans[i+1] =ans[i]*2;
                            }
                            else
                            {
                                ans[i] =ans[i-1]*2;
                                if(i+1<n)ans[i+1] =ans[i]/2;
                            }
                            i++;
                        }

                }
            }
        
        }
            
        
        
        // rep(i,n){cout<<ans[i]<<" ";}ce;
        if(cq){
            
            rep(i,n-1)
            {
                if((ans[i+1]/2 != ans[i] &&  ans[i+1]!=ans[i]/2)){cq=0;break;}
                
            }
        }
        if(cq){rep(i,n){cout<<ans[i]<<" ";}}
        else cout<<-1;
        ce;
    }

    return 0;
}

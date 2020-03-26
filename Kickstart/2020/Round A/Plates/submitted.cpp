#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int>  os;
#define up_bound(i) os.order_of_key(i) << endl; // the number of elements in the os less than i
#define access_idx(i) *os.find_by_order(i) // print the i-th smallest number in os(0-based)

#define ll long long int
#define ld double 
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define deb cerr << "Line no." << __LINE__
#define nl '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
#define P pair<ll,ll> 
#define F first
#define S second
const ll p_mod=9999999999999983;
const long double pi = 3.14159265358979323;
const ll N=1e6+9;
const ll mod=1e9+7;
typedef double f80;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){uniform_int_distribution<int> uid(l, r); return uid(rng); }
ll powerk(ll x, ll y);
ll mul(ll x, ll y);
ll add(ll x, ll y);
ll sub(ll x, ll y);

ll a[2002][2002],dp[2002][2002];

void solve()
{    
  ll n,m,p;
  cin>>n>>m>>p;
  rep(i,1,n)
    rep(j,1,m)
      {
        cin>>a[i][j];
        a[i][j]+=a[i][j-1];
      }
  memset(dp,-1,sizeof dp);
  rep(i,0,n)
  dp[i][0]=0;
  rep(i,1,n)
  {
    rep(j,1,p){
      rep(k,0,min((ll)j,m))
      if(dp[i-1][j-k]!=-1)
      {
        dp[i][j] = max(dp[i][j],dp[i-1][j-k]+a[i][k]);
      }
      //cout<<dp[i][j]<< " ";
    }
    //cout<<nl;
  }
  
  for(ll i=1;i<n+1;i++)
        {
            for(ll j=1;j<=p;j++)
            {
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
  cout<<dp[n][p]<<nl;

}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    cin>>t;
    rep(i,1,t)
    {
      cout<<"Case #"<<i<<": ";
      solve();
    }  
}
ll mul(ll x, ll y){return (x*y)%mod;}
ll add(ll x, ll y){return (x+y)%mod;}
ll sub(ll x, ll y){return (x-y+mod)%mod;}
ll powerk(ll x, ll y)
{
  if(y==0)return 1;
  if(y==1)return x%mod;
  if(y&1)
    return ((powerk((x*x)%mod, y/2)%mod)*x)%mod;
  else return powerk((x*x)%mod,y/2)%mod;
}


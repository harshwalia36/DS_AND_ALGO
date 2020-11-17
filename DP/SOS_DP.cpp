#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define  pb              push_back
#define  mp              make_pair
#define  vll             vector<ll>
#define  pll             pair <ll,ll>
#define  umap            unordered_map
#define  uset            unordered_set
#define  lb              lower_bound
#define  ub              upper_bound
#define  maxe            *max_element
#define  mine            *min_element
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        a/__gcd(a,b)*b
#define endl            "\n"
#define debug(x)        cout << " x =" << x << "\n";
#define init(c,a)       memset(c,a,sizeof(c))
#define mod             1000000007

using namespace std;

//------------------------------------------------
// ---------CODE HERE-----------------

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll A[1<<n];
    fors(i,1<<n)
    cin>>A[i];

    int F[1 << n] = {0};

  for(int i = 0; i<(1<<n); ++i)
	F[i] = A[i];
for(int i = 0;i < n; ++i)
{
   for(int mask = 0; mask < (1<<n); ++mask)
    {
	if(mask & (1<<i))
		F[mask] += F[mask^(1<<i)];
    }
}

fors(i,1<<n)
cout<<F[i]<<" ";
cout<<endl;

}









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

int **points;
int min_initial_health(int r,int c)
{
    int dp[r][c];
    for(int i=r-1;i>=0;i--)
    {
        for(int j=c-1;j>=0;j--)
        {
            if(i==r-1&&j==c-1)
            {
                dp[i][j]=min(0,points[i][j]);
            }
            else if(i==r-1)
                dp[i][j]=min(0,points[i][j]+dp[i][j+1]);
            else if(j==c-1)
                dp[i][j]=min(0,dp[i+1][j]+points[i][j]);
            else
                dp[i][j]=min(0,max(dp[i+1][j],dp[i][j+1])+points[i][j]);
        }
    }
    return abs(dp[0][0])+1;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  ll r,c;
  cin>>r>>c;

  points = new int*[r];
 for(int i = 0; i < r; ++i)
    points[i] = new int[c];


  fors(i,r)
  {
      fors(j,c)
      {
          cin>>points[i][j];
      }
  }

  cout<<min_initial_health(r,c);


}






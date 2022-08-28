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
#define MAXN  100001

using namespace std;

//------------------------------------------------
// ---------CODE HERE-----------------

vector <pair<ll,ll>> adj[MAXN];
bool vis[MAXN];
ll dis[MAXN];          //distance from source node

const int INF=1e9;

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,edges,x,y,wt;
    cin>>n>>edges;

    fors(i,MAXN)
     dis[i]=1e9;   //INF- 1e9

    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>wt;
        adj[x].pb(mp(y,wt));
    }

     // Assume the source node has a number (1):
     //bellman ford
    dis[1]=0;
    fors(k,n-1)  //relax each edge (n-1) times where n=no.of vertices
    {
         loop(i,1,n+1)            
        {
          for(int j=0;j<adj[i].size();j++)         // looping through all child of i
          {  int v=adj[i][j].first;                // child  of i

            if(dis[i]<INF)
            {
              if(dis[v]>adj[i][j].second+dis[i])
                dis[v]=adj[i][j].second+dis[i];
                
            }
          }
        }
    }

    loop(i,1,n+1)
    cout<<dis[i]<<" ";      //shortest distance from source to all nodes.

}






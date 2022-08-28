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

typedef pair<int, int> pi;

//------------------------------------------------
// ---------CODE HERE-----------------

vector <pair<ll,ll>> adj[MAXN];
bool vis[MAXN];
ll dis[MAXN];          //distance from source node

void Dijkstra_algo(int s)
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;

    pq.push(mp(0,s));

    while(!pq.empty())
    {
        pi p=pq.top();
        pq.pop();
        int v=p.second;
        int wei=p.first;  // no use further

        if(vis[v]) continue;                 // check if the popped vertex is visited before 

          vis[v]=true;                      //node whose children ae are gone to relax
        for(int i=0;i<adj[v].size();i++)
        {   int e=adj[v][i].first;  //node
            int w=adj[v][i].second;
            if(dis[e]>dis[v]+w)             // check if the next vertex distance could be minimized
            {
                dis[e]=dis[v]+w;
                pq.push(mp(dis[e],e));
            }
        }
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,edges,x,y,wt;
    cin>>n>>edges;

    fors(i,MAXN)
     dis[i]=1e18;

    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>wt;
        //only for directed edges
        adj[x].pb(mp(y,wt));
    }

     // Assume the source node has a number (1):
     //Dijkstra's algo
     dis[1]=0;

    Dijkstra_algo(1);

    loop(i,1,n+1)
    cout<<dis[i]<<" ";       //shortest distance from source to all nodes.


}






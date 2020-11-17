
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

vector <int> adj[100001];
vector<int> d(100001); //length of the shortest path  or we can say these as a level
vector<int> p(100001); //parent node
bool vis[100001];

int n,s,edges; //s=source , n=no. of vertex


void BFS(int s)
{
queue <int> q;

vis[s]=true;
q.push(s);
p[s]=-1;
d[s]=0;      //define the distance of root as 0
while(!q.empty())
{
    int v=q.front();
    cout<<v<<" ";
    q.pop();
    for(int i=0;i<adj[v].size();i++)
    {  int u=adj[v][i];
        if(!vis[u])
        {   vis[u]=true;
            q.push(u);
            d[u]=d[v]+1;        //shortest length from root or LEVEL
            p[u]=v;
        }
    }
}

}
 // If we have to restore and display the shortest path from the source to some vertex u, it can be done in the following manner:
void Shortest_Path(int u)
{
    if(!vis[u])
    cout<<"No Path\n";
else{
     vector<int> path;
    for(int v=u;v!=-1;v=p[v])
    {
        path.pb(v);
    }
    reverse(path.begin(),path.end());
    cout<<"Path:";
    for(int v:path)
    {
        cout<<v<<" ";
    }

}
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  cin>>n>>edges;
  int x;
  init(vis,false);
  int a,b;
  fors(i,edges)
  {
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
  }
  cout<<"enter the the vertex for shortest path:";
  cin>>x;

  BFS(1);


  Shortest_Path(x);
}





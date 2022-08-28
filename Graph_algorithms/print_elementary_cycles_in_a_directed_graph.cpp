#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define rloop(i,x,n) for(int i=x;i>=0;i--)
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
//priority_queue<pi, vector<pi>, greater<pi> > pq;


using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)      //in asc
{
    return (a.second < b.second);
}

//------------------------------------------------
// ---------CODE HERE-----------------

void printcycle(vector <int> v,int start)
{  int flag=0;
  for(int i=0;i<v.size();i++)
  {
      if(v[i]==start)
        flag=1;
      if(flag==1)      //not to print extra vertex not present in cycle
      cout<<v[i]<<" ";
  }
  cout<<endl;

}

void printDFSCycle(int u,vector <int> adj[],int col[],vector <int> &cycle)
{
    cout<<"u="<<u<<endl;
    col[u]=1;
    cycle.pb(u);
    for(int v:adj[u])
    {
        if(col[v]==0 )
            printDFSCycle(v,adj,col,cycle);

        if(col[v]==1)
            printcycle(cycle,v);

    }
    col[u]=2;
    cycle.pop_back();
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int n,edges,u,v;
  cin>>n>>edges;
  vector <int> adj[n+1];         //1-n
  for(int i=0;i<edges;i++)
  {
      cin>>u>>v;
      adj[u].pb(v);
  }
  int col[n+1]={0};
  vector <int> cycle;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0)
            printDFSCycle(i,adj,col,cycle);
    }
}





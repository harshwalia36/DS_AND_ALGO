
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
//priority_queue<pi, vector<pi>, greater<pi> > pq;


using namespace std;

const int MAX = 1e4 + 5;
int parent[MAX],Size[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

//------------------------------------------------
// ---------CODE HERE-----------------
void initialize()
{
    fors(i,MAX)
    {
        parent[i]=i;      //meaning that it is its own ancestor.
        Size[i]=1;          // initialize size=1
    }
}

int find_set(int v)                  // this function  find the root/leader of the tree with tree compression
{

    if(parent[v]==v)
        return v;
    return parent[v]=find_set(parent[v]);
}

void union1(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {

        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;    //larger size is always a parent
        Size[a]+=Size[b];
    }
}

int kruskal(pair <long long, pair<int, int> > p[])
{
    int x,y;
    ll cost,minimumCost=0;
    fors(i,edges)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
          // Check if the selected edge is creating a cycle or not
        if(find_set(x)!=find_set(y))
        {
         minimumCost+=cost;
         union1(x,y);
        }
    }
    return minimumCost;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

      int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;

}





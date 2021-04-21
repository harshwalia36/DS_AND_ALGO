
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

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];          //set of MST as a boolean
vector <PII> adj[MAX];


long long prim(int x)
{
    priority_queue <PII, vector<PII> ,greater<PII> > Q;     //min-priority queue
    int y;
    ll minimumCost=0;
    PII p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        p=Q.top();
        Q.pop();
        x = p.second;     //next vertex
        // Checking for cycle
        if(marked[x] == true)
            continue;
            minimumCost+=p.first;
            marked[x]=true;
            fors(i,adj[x].size())
            {
                y=adj[x][i].second;
                if(marked[y]==false)
                    Q.push(adj[x][i]);          //Insert the vertices, that are connected to growing spanning tree, into the Priority Queue.
            }
    }
    return minimumCost;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);                  // we can select any vertex as a starting vertex
    cout << minimumCost << endl;


}





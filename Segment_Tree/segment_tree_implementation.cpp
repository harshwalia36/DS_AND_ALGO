// Range sum query using segment Tree


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
#define  maxe            *max_element        #return a pointer to max_element
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

ll *tree;
ll *a;

void build(int node,int start,int end)
{
    if(start==end)
     tree[node]=a[start];
     else{
         int mid=(start+end)/2;
         build(2*node+1,start,mid);
         build(2*node+2,mid+1,end);
         tree[node]=tree[2*node+1]+tree[2*node+2];
     }
}

void update(int node,int start,int end,int idx, int val)
{    if(start==end)
    {
        tree[node]+=val;
        a[idx]+=val;
    }
    else{
        int mid=(start+end)/2;
     if(start<=idx && idx<=mid)
     {
        update(2*node+1,start,mid,idx,val);
     }
     else{
         update(2*node+2,mid+1,end,idx,val);
     }
     tree[node]=tree[2*node+1]+tree[2*node+2];
    }
}

int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
    {
          return 0;
    }
    if( l<=start && end<=r)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    int p1=query(2*node+1,start,mid,l,r);
    int p2=query(2*node+2,mid+1,end,l,r);
    return p1+p2;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  ll n,q;
  cin>>n>>q;

   a=new ll[n];

   fors(i,n)
   cin>>a[i];

  int x = (int)(ceil(log2(n)));

    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

     tree=new ll[max_size];
     build(0,0,n-1);
    while(q--)
    {
        char s;ll l,r;
        cin>>s>>l>>r;
        if(s=='q')
        {
            cout<<query(0,0,n-1,l-1,r-1)<<endl;
        }
        else if(s=='u')
        {
            update(0,0,n-1,l-1,r-a[l-1]);
        }

    }





}






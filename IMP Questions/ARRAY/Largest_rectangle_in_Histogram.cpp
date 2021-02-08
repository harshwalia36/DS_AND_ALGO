
#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define rloop(i,n,x) for(int i=n;i>=x;i--)
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

//------------------------------------------------
// ---------CODE HERE-----------------

ll maxAreaHistogram(ll ar[],ll n)
{
   ll left[n],right[n],area,maxx=INT_MIN;

   stack <ll> st,st2;
   //LEFT
   fors(i,n)
   {
       if(st.empty())
       {
         left[i]=0;
         st.push(i);
       }
       else{
          while(!st.empty() && ar[i]<=ar[st.top()])
          {
              st.pop();
          }
          if(st.empty())
            left[i]=0;
          else
            left[i]=st.top()+1;
          st.push(i);
       }
   }
   //Right
    rloop(i,n-1,0)
   {
       if(st2.empty())
       {
         right[i]=n-1;
         st2.push(i);
       }
       else{
          while(!st2.empty() && ar[i]<=ar[st2.top()])
          {
              st2.pop();
          }
           if(st2.empty())
            right[i]=n-1;
          else
            right[i]=st2.top()-1;
          st2.push(i);
       }
   }
   fors(i,n)
   {
       area=ar[i]*(right[i]-left[i]+1);
       if(maxx<area)
        maxx=area;
   }
   return maxx;

}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  ll n;
  cin>>n;
  ll ar[n];
  fors(i,n)
  cin>>ar[i];

  cout<<maxAreaHistogram(ar,n)<<endl;
}





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

//------------------------------------------------
// ---------CODE HERE-----------------



int maxAreaHistogram(int ar[],int n)
{
   int left[n],right[n],area,maxx=INT_MIN;

   stack <int> st,st2;
   //LEFT
   for(int i=0;i<n;i++)
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
    for(int i=n-1;i>=0;i--)
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
   for(int i=0;i<n;i++)
   {
       area=ar[i]*(right[i]-left[i]+1);
       if(maxx<area)
        maxx=area;
   }
   return maxx;

}
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    int ar[m]={0},maxx=INT_MIN,area;

    area=maxAreaHistogram(M[0],m);
    maxx=area;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   if(M[i][j]==1)
            M[i][j]+=M[i-1][j];
        }
       area=maxAreaHistogram(M[i],m);
       if(area>maxx)
       maxx=area;
    }
    return maxx;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int A[4][4] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is "
         << maxArea(A,4,4);

}






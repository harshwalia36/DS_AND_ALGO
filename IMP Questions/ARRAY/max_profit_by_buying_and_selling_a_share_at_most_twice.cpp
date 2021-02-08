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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)      //in asc
{
    return (a.second < b.second);
}

//------------------------------------------------
// ---------CODE HERE-----------------
int max_profit(int price[],int n)
{
   int profit[n];
   init(profit,0);
   int maxPrice=price[n-1];
   for(int i=n-2;i>=0;i--)
   {
       if(maxPrice<price[i])
          maxPrice=price[i];

        profit[i]=max(maxPrice-price[i],profit[i+1]);
   }


    /* Get the maximum profit with two transactions allowed
       After this loop, profit[n-1] contains the result */
   int minPrice=price[0];
   loop(i,1,n)
   {
       if(minPrice>price[i])
        minPrice=price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        //    profit of other trans. stored in profit[i]
       profit[i]=max(profit[i]+(price[i]-minPrice),profit[i-1]);
   }
   return profit[n-1];
}
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int price[n];
    fors(i,n)
    {
        cin>>price[i];
    }
    cout<<max_profit(price,n)<<endl;

}






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
void right_rotate(int a[],int ind1,int ind2,int n)
{
    int temp=a[ind2];
    for(int i=ind2;i>ind1;i--)
    {
        a[i]=a[i-1];
    }
    a[ind1]=temp;

}

void Rearrange(int a[],int n)
{    int ind1=-1,ind2=-1;
    fors(i,n)
    {
        if(i%2==0&& a[i]>=0)    //at even positions negative number is there
        {
            ind1=i;
            ind2=-1;
            loop(j,i+1,n)
            {
              if(a[j]<0)
              {ind2=j;break;}
            }
            if(ind2!=-1)
            right_rotate(a,ind1,ind2,n);
        }
        else if(i%2!=0&&a[i]<0){         //at odd position positive number is there
            ind1=i;
            ind2=-1;
             loop(j,i+1,n)
            {
              if(a[j]>=0)
              {ind2=j;break;}
            }
            if(ind2!=-1)
            right_rotate(a,ind1,ind2,n);
        }

    }


}

int main()
{
    int n;
    cin>>n;
    int a[n];
    fors(i,n)
    cin>>a[i];
    Rearrange(a,n);
    fors(i,n)
    {
        cout<<a[i]<<" ";
    }
}

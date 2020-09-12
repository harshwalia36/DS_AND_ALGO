
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
// ---------CODE HERE----------------------

ll BIT[1000006][26]={0},n;
string s;

void update(ll idx1,ll idx2,ll val)
{
    for( ;idx1<=n;idx1+=idx1&(-idx1))
    {
        BIT[idx1][idx2]+=val;
    }
}
ll query(ll idx1,ll idx2)
{
    ll sum=0;
     for( ;idx1>0;idx1-=idx1&(-idx1))
     {
         sum+=BIT[idx1][idx2];
     }
     return sum;

}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 ll q;
 cin>>n>>q;
 cin>>s;
 fors(j,n)
 {
     update(j+1,s[j]-'a',1);
 }
 while(q--)
 {
     ll t;
 cin>>t;
 if(t==0)
 {
     ll index;
     char c;
     cin>>index>>c;
     update(index,s[index-1]-'a',-1);
     s[index-1]=c;
     update(index,s[index-1]-'a',1);

 }
 else{
     ll L,R,k;
     cin>>L>>R>>k;
     ll ans=0,j;
     for(j=0;j<26;j++)
     {
         ans+=query(R,j)-query(L-1,j);
         if(ans>=k)
         break;
     }
     if(ans>=k)
     cout<<char(j+'a')<<endl;
     else
     cout<<"Out of range"<<endl;
 }
 }



}






#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define rloop(i,x,n) for(int i=x;i>=0;i--)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define init(c,a)       memset(c,a,sizeof(c))

using namespace std;

int main() {
	 int t;
	cin>>t;
	while(t--)
	{
	  string s;
	  cin>>s;
	  int n=s.size();
	  int dp[n][n];
	  init(dp,0);

	  fors(i,n)
	    dp[i][i]=1;

	 fors(i,n-1)
	 {
	     if(s[i]==s[i+1])
	       dp[i][i+1]=1;
	 }

	 loop(len,2,n)
	 {
	     for(int i=0;i+len<n;i++)
	     {
	         int j=i+len;
	         dp[i][j]=dp[i+1][j-1] && (s[i]==s[j]);

	     }
	 }
	 int start=0,e=0;
	  for(int len=n-1;len>=0;len--)
	 {  int i,j;
	     for(i=0;i+len<n;i++)
	     {
	          j=i+len;
	         if(dp[i][j]==1)
	         {
	           start=i;e=j; break;
	         }
	     }
	     if(i+len!=n)
	     break;
	 }
	 cout<<s.substr(start,e-start+1)<<endl;


	}

	return 0;
}

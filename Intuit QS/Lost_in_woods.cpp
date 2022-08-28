#include<bits/stdc++.h>
using namespace std;

int main()
{
 
 int n;
 cin>>n;
 char ch[n];
 for(int i=0;i<n;i++)
 {
    cin>>ch[i];
 }
 string ans;

int i=0;
int f=0;
if(n==1)
ans='W';
else{
    while(i<n-1)
{
    f=0;
    if(ch[i+1]=='_')
    {ans+='W'; i++;}
    else if(ch[i+1]=='*')
    {   while(ch[i+1]=='*')
        {
            i++;
            f=1;
        }
        if(f)
        ans+='J';
        i++;
    }
    else if(ch[i+1]=='D')
    {
        ans+='W';
        i++;
    }
}
}

 cout<<ans<<endl;
}
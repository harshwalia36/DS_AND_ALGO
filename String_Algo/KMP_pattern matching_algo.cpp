#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
using namespace std;

//LPS- Longest prefix which is also a suffix.

string pat,text;
ll *lps,m,n;

void computeLPSArray()
{
    int j=0,i=1;
    lps[0]=0;
    while(i<n)
    {
        if(pat[j]==pat[i])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else  // (pat[i] != pat[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
                  // Also, note that we do not increment
                // i here
            }
            else{ // if (j == 0)
                 lps[i]=0;
                 i++;
            }
        }

    }
}

void KMPSearch()
{
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray();

    int j=0;   //ind for patteren
    int i=0;   //ind for text
    while(i<m)
    {
        if(pat[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            cout<<"Found Pattern at index :"<<i-j<<endl;
            j=lps[j-1];    //set index of pattern after a prefix which is equal to suffix

        }

        // mismatch after j matches
        else if(i<m && pat[j]!=text[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if(j!=0)
            {
                j=lps[j-1];
            }
            else{
                i++;   //i only increase when j=0
            }
        }
    }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     cin>>text;
     cin>>pat;
     m=text.length();
     n=pat.length();
     lps=new ll[n];
     KMPSearch();


}

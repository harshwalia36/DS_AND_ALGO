#include<bits/stdc++.h>

#define MOD 1000000007
using namespace std;
  
// capList[i]'th vector contains the list of persons having a cap with id i
// id is between 1 to 100 so we declared an array of 101 vectors as indexing
// starts from 0.
vector<int> capList[101];
  
// dp[2^10][101] .. in dp[i][j], i denotes the mask i.e., it tells that
// how many and which persons are wearing cap. j denotes the first j caps
// used. So, dp[i][j] tells the number ways we assign j caps to mask i
// such that none of them wears the same cap
int dp[1025][101];
  
// This is used for base case, it has all the N bits set
// so, it tells whether all N persons are wearing a cap.
int allmask;

countWaysUtil(int mask,int i)
{
     // If all persons are wearing a cap so we
    // are done and this is one way so return 1
  if(allmask==mask)
  return 1;

    // If not everyone is wearing a cap and also there are no more
    // caps left to process, so there is no way, thus return 0;
    if(i>100)
    return 0;

    // If we already have solved this subproblem, return the answer.
    if (dp[mask][i] != -1) return dp[mask][i];
  
    // Ways, when we don't include this cap in our arrangement
    // or solution set.
    long long int ways = countWaysUtil(mask, i+1);

    int size=capList[i].size();    //no. of valid persons which can wear ith cap
    
    for(int j=0;j<size;j++)
    {   
        // if person capList[i][j] is already wearing a cap so continue as
        // we cannot assign him this cap
        if(mask & (1<<capList[i][j]))
        continue;
        
         // Else assign him this cap and recur for remaining caps with
        // new updated mask vector
        else
        ways+=countWaysUtil(mask | (1<<capList[i][j]),i+1);
        ways%=MOD;
    }
    return dp[mask][i]=ways;
}

int CountWays(int n)
{
    string temp,str;
    int x;
    getline(cin,str);  //to get rid of new line character
    for(int i=0;i<n;i++)
    {
        getline(cin,str); 
        stringstream ss(str);   // Used for breaking words
  
        // while there are words in the streamobject ss
        while(ss>>temp)     // operator >> — read something from the stringstream object
        {
            stringstream s;
            s<<temp;                     // operator << — add a string to the stringstream object.
            s>>x;                       // converting the string into integer

            capList[x].push_back(i);

        }

        allmask=(1<<n)-1;

         // Initialize all entries in dp as -1
        memset(dp, -1, sizeof dp);
  
        // Call recursive function count ways
        cout << countWaysUtil(0, 1) << endl;
        
    }
    return 0;
}
int main()
{
    int n; // no. of persons
    cin>>n;
    CountWays(n);

}
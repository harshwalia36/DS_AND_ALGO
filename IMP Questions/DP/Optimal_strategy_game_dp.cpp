
long long maximumAmount(int arr[], int n)
{
    int dp[n][n]={0};

    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1]=max(arr[i],arr[i+1]);
    }

    for(int l=3;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}

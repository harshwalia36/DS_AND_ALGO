class Solution {
  public:
  int kadnesAlgo(int arr[],int n)
  {
      int ma=INT_MIN;
      int u=0;
    for(int i=0;i<n;i++)
    {
        u+=arr[i];
        ma=max(ma,u);
        if(u<0)
        u=0;
    }
    return ma;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans=INT_MIN;
        for(int l=0;l<C;l++)
        {  int arr[R]={0};
            for(int r=l;r<C;r++)
            {
                for(int i=0;i<R;i++)
                {
                    arr[i]+=M[i][r];
                }
                ans=max(ans,kadnesAlgo(arr,R));
            }
        }
        return ans;
    }
};

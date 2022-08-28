int dirX[5] = {0, 1, 0, -1, 0};
       int dirY[5] = {0, 0, 1, 0, -1};
	   int keypad[4][3]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, { -1, 0, -1}};

	   long long dp[10][26];

	long long helper(int r,int c, int N)
    {

         if(N==1)
         {
             int number=keypad[r][c];
             return dp[number][N]=1;                  //memoization
         }
         long long totalcount=0;
         for(int i=0;i<5;i++)
         {
             int newr=r+dirX[i];
             int newc=c+dirY[i];

             if(newr>=0 && newr<4  && newc>=0 && newc<3 && keypad[newr][newc]!=-1)
             {
                 int number=keypad[newr][newc];

                 if(dp[number][N]==-1)
                 {
                     dp[number][N]=helper(newr,newc,N-1);       //Memoizaation
                 }
                 totalcount+=dp[number][N];
             }
         }
         return totalcount;
    }

	long long getCount(int N)
	{

	   for(int i=0;i<10;i++)
	   {
	       for(int j=0;j<26;j++)
	       dp[i][j]=-1;
	   }
	   long long ans=0;
	   for(int i=0;i<4;i++)
	   {
	       for(int j=0;j<3;j++)
	       {
	           if(keypad[i][j]!=-1)
	            ans+=helper(i,j,N);
	       }
	    }
	    return ans;
	}


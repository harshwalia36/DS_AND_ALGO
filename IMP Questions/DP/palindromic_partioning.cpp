    int palindromicPartition(string str)
    {
        int n=str.size();
        int totalpar[n],pal[n][n];

        for(int i=0;i<n;i++)
        pal[i][i]=1;

      for (int L = 2; L <= n; L++) {
       // For substring of length L, set different possible starting indexes
       for (int i = 0; i < n - L + 1; i++) {
         int j = i + L - 1; // Set ending index

         // If L is 2, then we just need to compare two characters. Else
         // need to check two corner characters and value of P[i+1][j-1]
         if (L == 2)
         pal[i][j] = (str[i] == str[j]);
         else
         pal[i][j] = (str[i] == str[j]) && pal[i + 1][j - 1];
         }
       }

        for(int i=0;i<n;i++)
        {
            if(pal[0][i])
                {
                  totalpar[i]=0;
                }
                else{
                    totalpar[i]=INT_MAX;
                    for(int j=0;j<i;j++)
                    {
                        if(pal[j+1][i]  &&  totalpar[j]+1<totalpar[i])
                         totalpar[i]=totalpar[j]+1;
                    }
                }
        }
        return totalpar[n-1];
    }
};

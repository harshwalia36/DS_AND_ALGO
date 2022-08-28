class Solution{
public:
int mod=1003;
    long long countWays(int N, string S){
        string op="";
        string symb="";
        for(int i=0;i<N;i+=2)
        {
            op+=S[i];
        }
        for(int i=1;i<N;i+=2)
        {
            symb+=S[i];
        }

        int n=op.size();


        long long T[n][n]={0};  //T(i, j) represents the number of ways to parenthesize the symbols between i and j
                        //(both inclusive) such that the subexpression between i and j evaluates to true.
        long long F[n][n]={0};   //F[i][j]  represents the number of ways to parenthesize the symbols between i and j
                        //(both inclusive) such that the subexpression between i and j evaluates to false.

        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)    //way of diagonal traversal
            { T[i][j]=0;
              F[i][j]=0;
                if(g==0)
                {
                    if(op[i]=='T')
                    {
                        T[i][j]=1;
                        F[i][j]=0;
                    }
                    else{
                        T[i][j]=0;
                        F[i][j]=1;
                    }
                }
                else{
                    for(int k=i;k<j;k++)
                    {
                        string ch;
                        ch=symb[k];

                        long long ltc=T[i][k];   //ltc- left true count
                        long long rtc=T[k+1][j];   //rtc- right true count

                        long long lfc=F[i][k];   //ltc- left false count
                        long long rfc=F[k+1][j];  //rtc- right false count
                        if(ch=="&")
                        {
                           T[i][j]+=(ltc*rtc)%mod;
                           F[i][j]+=(ltc*rfc + lfc*rtc + lfc*rfc)%mod;
                        }
                        else if(ch=="|")
                        {
                            T[i][j]+=(ltc*rfc + lfc*rtc + ltc*rtc)%mod;
                            F[i][j]+=(lfc*rfc)%mod;
                        }
                        else{
                            T[i][j]+=(ltc*rfc+lfc*rtc)%mod;
                            F[i][j]+=(lfc*rfc +ltc*rtc)%mod;
                        }
                    }
                }
            }
        }
        return T[0][n-1]%mod;
    }

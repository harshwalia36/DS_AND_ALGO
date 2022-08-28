#include <iostream>
using namespace std;

#define MAX_N 100

int n,num;
struct E{
    int x,y;
};
E elem[5];

int mat[22][22],dist[22][22];

class Queue{
    public:
    int front,rear;
    E A[10000];
    Queue()
    {
        front=0;
        rear=0;
    }
    void push(E e)
    {
        A[rear].x=e.x;
        A[rear].y=e.y;
        rear++;
    }
    E pop()
    {
        return A[front++];
    }
     bool isEmpty(){
        return front>=rear?1:0;
    }

};
bool isValid(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=n && mat[x][y]==1)
        return 1;
    return 0;
}

void bfs(int x,int y)
{
    bool vis[22][22];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            vis[i][j] = 0;
        }

    Queue q;
    E ne;
    ne.x=x;ne.y=y;
    dist[x][y] = 0;
    q.push(ne);
    vis[ne.x][ne.y]=1;
    int xx[4]={-1,1,0,0};
    int yy[4]={0,0,-1,1};

    while(!q.isEmpty())
    {
        E el=q.pop();

        for(int i=0;i<4;i++)
        {
            int newX=el.x+xx[i];
            int newY=el.y+yy[i];

            if(isValid(newX,newY) && !vis[newX][newY])
            {
                dist[newX][newY]=dist[el.x][el.y]+1;

                //cout<<dist[newX][newY]<<endl;
                
                E nn;
                nn.x = newX, nn.y = newY;
                q.push(nn);
                vis[newX][newY]=1;
                
            }
        }
    }

}


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       cin>>n>>num;
        for(int i=0;i<num;i++)
         cin>>elem[i].x>>elem[i].y;

         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 cin>>mat[i][j];
                 dist[i][j]=INT_MAX;
                
             }
         }
         int res=INT_MAX;
         int ans=0;

         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(mat[i][j]==1)
                 {
                     bfs(i,j);
                    
                    ans=0;
                    for(int k=0;k<num;k++)
                     {ans=max(ans,dist[elem[k].x][elem[k].y]);
                    //   cout<<"ans:"<<ans<<endl;
                     }

                     res=min(res,ans);
                 }
             }
         }
        cout<<res<<endl;
   }
}



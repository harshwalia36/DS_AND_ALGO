#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/

int w[35][5];
int mask[35];
int n;  //no. of warmhole
int ans=INT_MAX;

int dist(int x1,int y1,int x2,int y2)
{
    int d=abs(x1-x2)+abs(y1-y2);
    return d;
}
void wormhole(int sX,int sY,int dX,int dY,int value)
{
    ans=min(ans,dist(sX,sY,dX,dY)+value);

    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(mask[i]==0)
        {mask[i]=1;

        /* Choose lower end of wormhole */
        temp=value+dist(sX,sY,w[i][0],w[i][1])+w[i][4];
        wormhole(w[i][2],w[i][3],dX,dY,temp);
    

        /* Choose upper end of wormhole */
        temp=value+dist(sX,sY,w[i][2],w[i][3])+w[i][4];
        wormhole(w[i][0],w[i][1],dX,dY,temp);
        

        mask[i]=0;          //backtrack
        }
    }
}

int main()
{
    int sX,sY,dX,dY;
    cin>>sX>>sY>>dX>>dY;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        mask[i]=0;
        for(int j=0;j<5;j++)
         cin>>w[i][j];
    }

    wormhole(sX,sY,dX,dY,0);
    cout<<"min_dist="<<ans<<endl;
}
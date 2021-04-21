//CONCEPT - We can consider the chessboard as unweighted and undirected graph. We can always find shortest path in an unweighted graph using Breadth First Search.

/*Every cell in the chessboard can be considered as a different vertex connected to atmost 8 other vertices where the knight can reach from the current cell.
The possible moves for a Knight when it is at cell (x, y) are:
(x-2, y-1)
(x-2, y+1)
(x-1, y-2)
(x-1, y+2)
(x+2, y-1)
(x+2, y+1)
(x+1, y-2)
(x+1, y+2) */

int r[8]={2, 2,-2,-2,1,-1, 1,-1};
int c[8]={1,-1, 1,-1,2, 2,-2,-2};

bool isValid(int x,int y,int N)
{
    if(x>=1 && y>=1 && x<=N && y<=N)
    return true;

    return false;
}
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    queue <pair<int,int>> q;
	    bool vis[N+1][N+1]={false};

	    unordered_map <int,int> d;       //<r*N+c,cnt>
	    q.push(make_pair(KnightPos[0],KnightPos[1]));
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    d[N*KnightPos[0]+KnightPos[1]]=0;
	    while(!q.empty())
	    {
	        pair <int,int> pp=q.front();
	        int curx=pp.first,cury=pp.second;
	        q.pop();
	        for(int i=0;i<8;i++)
	        {  int nextR=curx+r[i],nextC=cury+c[i];
	            if(!vis[nextR][nextC] && isValid(nextR,nextC,N))
	            {
	               vis[nextR][nextC]=true;  // IN BFS WE mark visited when we push node in queue
	              q.push(make_pair(nextR,nextC));
	              d[N*nextR+nextC]=d[N*curx+cury]+1;
	            }

	        }
	        if(curx==TargetPos[0] && cury==TargetPos[1])
	         break;
	    }
	    return d[N*TargetPos[0]+TargetPos[1]];
	}
};

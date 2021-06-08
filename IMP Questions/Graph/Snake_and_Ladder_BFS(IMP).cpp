class Solution {
public:
    pair<int,int> getCoordinate(int n,int currSquare)
    {
         /*
            To get row of currSquare in standard matrix, row = (currSquare-1)/n;
            But, since we are numbering from bottom in this problem, we need to subtract it from                n-1. => n-1-(currSquare-1)/n
            To get col of currSquare in standard matrix, col = (currSquare-1)%n;
            But, we need to observe that when we're traversing right to left in matrix, when (n%2               == 0/1 || row % 2 == 0/1)
            So, whenever we have the above condition satisfying, we need to subract col from n-1
        */
        int row=n-1-(currSquare-1)/n;
        int rem=(currSquare-1)%n;
        int col=(n%2==row%2)?n-1-rem:rem;   //depend on ending number of rows
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
       int totalSquares=board.size()*board.size(),n=board.size();
        //{current square number, number of time dice rolled}
        queue<pair<int, int>> Q;
        Q.push({1, 0});
        vector<bool> visited(n*n+1,false);
        visited[1]=true; //mark 1st square as visited
        //BFS
        while(!Q.empty())
        {
            auto curr=Q.front();
            Q.pop();
             //if we have reached destination, return number of times dice was rolled to get here.
            if(curr.first == totalSquares)
                return curr.second;

            int currSquare = curr.first, currRoll = curr.second; //level

            for(int i=1;i<=6 && currSquare+i<=totalSquares;i++)
            {
                auto nextSquare=getCoordinate(n,currSquare+i);
                int destSquare=board[nextSquare.first][nextSquare.second] == -1 ? currSquare + i : board[nextSquare.first][nextSquare.second];

                if(!visited[destSquare])
                {
                    visited[destSquare]=true;
                    Q.push({destSquare,currRoll+1}); //pushing unvisited destination square,next level
                }
            }

        }
        return -1;   // if q becomes empty and we have not reach destination
    }
};

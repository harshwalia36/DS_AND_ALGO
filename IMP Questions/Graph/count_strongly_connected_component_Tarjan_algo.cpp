void DFS(int u,vector<int> & disc,vector<int> &low, stack <int> &myStack,vector<bool> & presentInStack,vector<int> adj[],int& cnt)
    {
        static int time=0;
        disc[u]=low[u]=time;
        time++;
        myStack.push(u);
        presentInStack[u]=true;
        for(auto v:adj[u])
        {
            if(disc[v]==-1)
            {
                DFS(v,disc,low,myStack,presentInStack,adj,cnt);
                low[u]=min(low[u],low[v]);
            }
            else if(presentInStack[v])   //Back Edge
             low[u]=min(low[u],disc[v]);
        }
         if(low[u]==disc[u])
         {
             cnt++;
             while(myStack.top()!=u)
             {
                 presentInStack[myStack.top()]=false;
                 myStack.pop();
             }
             presentInStack[myStack.top()]=false;
             myStack.pop();
         }
    }

    int findSCCs_Tarjan(int V, vector<int> adj[]) {   //tarajan's algo
        vector <int> low(V,-1),disc(V,-1);
        vector <bool> presentInStack(V,false);
        stack <int> s;
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(disc[i]==-1)  //not visited
             DFS(i,disc,low,s,presentInStack,adj,cnt);
        }
        return cnt;
    }

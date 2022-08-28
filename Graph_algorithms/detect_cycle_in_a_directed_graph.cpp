
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N];
vector<int> cycles[N];

//color means
//0 - not visited
//1-  visted
//2- exited the visited vertex
bool DFSCycle(int v,int color[]){
    color[v]=1;  //marking as visited
    for(auto u:adj[v])
    {
        if(color[u]==0 && DFSCycle(u,color);)       // not visited
        {
            return true;

        }
        if(color[u]==1)  // if it is already visited cycle is there
        {
            return true;       //while backtracking child is already visited return true till source node once find cycle
        }
    }
    color[v]=2;  // if all children are visited mark as visited and exited
    return false;

}
void insert(int u, int v){
   adj[u].push_back(v);
}

int main(){
   int n,edges,u,v;
   cin>>n>>edges;
   for(int i=0;i<edges;i++)
   {
       cin>>u>>v;
       insert(u,v);
   }

   int color[n+1]={0};


   cout<<DFSCycle(1,color);
}

void DFS(int s)
{
    vis[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(!vis[u])
            DFS(u);
    }
}

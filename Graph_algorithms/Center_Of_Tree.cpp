vector<int> CenterOfTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> degree(n,0);
        // build adjaceny list && compute degrees for the nodes;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        // nodes having degree of 1 or 0 can be a leaf node
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(degree[i]<=1){
                leaves.push_back(i);
                degree[i]=0; // once added to the leaves array, make it zero because it won't be processed again.
            }
        }

        int totalLeaves = leaves.size();
        while(totalLeaves<n){
            vector<int> newLeaves; // The ancestors of the current leaves will become new leaves while exploring the tree/graph in a converging manner
            for(auto leaf : leaves){
                for(int node : adj[leaf]){ // traversing to all the connected components
                    degree[node]--;
                    if(degree[node]==1){
                        newLeaves.push_back(node);
                    }
                }
            }
            totalLeaves+=newLeaves.size();
            leaves = newLeaves;
        }
        return leaves;
    }
};

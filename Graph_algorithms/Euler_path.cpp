/*
Explanation

First keep going forward until you get stuck. That's a good main path already. Remaining tickets form cycles which are found on the way back and get merged into
 that main path. By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy - the end part of the path 
 has already been written, the start part of the path hasn't been written yet, so just write down the cycle now and then keep backwards-writing the path.

Example:

https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B   link of explanation

From JFK we first visit JFK -> A -> C -> D -> A. There we're stuck, so we write down A as the end of the route and retreat back to D. 
There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again, retreat and write down the airports while doing so: Write 
down D before the already written A, then JFK before the D, etc. When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A. 
Then we retreat further along the original path, prepending C, A and finally JFK to the route, ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.
*/

 //EULER Path
    vector<string> ans;
    void dfs(string s,map <string,multiset<string>> &adj)
    {
      while(adj[s].size())  
      {
          string ss=*adj[s].begin();
          adj[s].erase(adj[s].begin()) ;
          dfs(ss,adj);
      }
        ans.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();
        map <string,multiset<string>> adj;
        for(int i=0;i<tickets.size();i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        
        dfs("JFK",adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
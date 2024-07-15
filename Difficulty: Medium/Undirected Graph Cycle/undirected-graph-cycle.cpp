//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        
        vector<int>vis(v+1,0);
        function<bool(int,int)> bfs=[&](int src, int prnt)->bool{
        queue<pair<int,int>>q;
        q.push({src,prnt});
        vis[src]=1;
        while(!q.empty())
        {
            int curr=q.front().first;
            int parent= q.front().second;
            q.pop();
            for(auto i:adj[curr])
            {
                  if(i!=parent)
                  {
                        if(vis[i])
                        {
                            return true;
                        }
                        else
                        {
                            vis[i]=1;
                            q.push({i,curr});
                        }
                  }
            }
        }
        };
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                bool ans = bfs(i,-1);
                if(ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
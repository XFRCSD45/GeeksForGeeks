//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>adj[], int i, vector<bool>&visited)
    {
     visited[i]=true;
     for(auto x:adj[i])
     {
         if(!visited[x])
         {
             dfs(adj,x,visited);
         }
     }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>visited(V,false);
	    int mv=-1;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(adj,i,visited);
	            mv=i;
	        }
	    }
	     fill(visited.begin(), visited.end(), false);
          dfs(adj, mv, visited);
 
            for (bool v : visited) 
            {
                if (!v) {
                    return -1;
                }
            }
 
    return mv;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
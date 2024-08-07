//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>>pq;
        pq.push({S,0});
        vector<int>dist(n,1e9);
        dist[S]=0;
        while(!pq.empty())
        {
             int curr=pq.top().first;
             int step=pq.top().second;
             pq.pop();
             for(auto i:adj[curr])
             {
                 int node=i[0];
                 int w=i[1];
                 if(dist[node]>w+step)
                 {
                      dist[node]=w+step;
                      pq.push({node,dist[node]});
                 }
             }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
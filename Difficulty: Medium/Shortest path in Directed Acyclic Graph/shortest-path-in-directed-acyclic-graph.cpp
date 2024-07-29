//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int>dist(n,1e9);
        vector<vector<pair<int,int>>>g(n);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            g[u].push_back({v, w});
        }
          
	    vector<int>vis(n,0);
	    stack<int>s;
	     function<void(int)> dfs = [&](int curr)->void{
          
          vis[curr]=1;
          
          for(auto i : g[curr])
          {
              if(!vis[i.first])
              {
                  dfs(i.first);
              }
             
          }
         s.push(curr);
        };
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               dfs(i);
            }
        }
        dist[0]=0;
        while(!s.empty())
        {
            int curr= s.top();
            s.pop();
            for(auto i:g[curr])
            {
                if((dist[curr]+i.second )<dist[i.first])
                {
                    dist[i.first]=dist[curr]+i.second ;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
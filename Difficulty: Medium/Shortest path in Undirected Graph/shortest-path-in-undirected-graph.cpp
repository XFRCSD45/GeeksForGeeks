//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
         vector<int>dist(n,1e9);
        vector<vector<int>>g(n);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<pair<int,int>>q;
        dist[src]=0;
        q.push({src,0});
        while(!q.empty())
        {
              pair<int,int>p=q.front();
              q.pop();
              for(auto i:g[p.first])
              {
                    if(p.second+1<dist[i])
                    {
                        dist[i]=p.second+1;
                        q.push({i,dist[i]});
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& v) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++)
        {
          int u=v[i][0];
          int s=v[i][1];
          int w=v[i][2];
          adj[u].push_back({s,w});
          adj[s].push_back({u,w});
        }
        vector<int>parent(n+1,-1);
         set<pair<int,int>>pq;
         
        pq.insert({0,1});
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        while(!pq.empty())
        {
             int step=(*(pq.begin())).first;
             int curr=(*(pq.begin())).second;
             pq.erase(pq.begin());
             for(auto i:adj[curr])
             {
                 int node=i.first;
                 int w=i.second;
                 if(dist[node]>w+step)
                 {
                     pq.erase({dist[node],node});
                     parent[node]=curr;
                      dist[node]=w+step;
                      pq.insert({dist[node],node});
                 }
             }
        }
        
        if(dist[n]==1e9)
        {
            return {-1};
        }
        vector<int>path;
        int curr=n;
        while(curr!=-1)
        {
            path.push_back(curr);
            curr=parent[curr];
        }
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        // for(int i=0;i<path.size();i++)
        // {
        //     cout<<path[i]<<" ";
        // }
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
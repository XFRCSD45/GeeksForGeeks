//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
                if(grid[source.first][source.second]==0)
        {
            return -1;
        }
        int n= grid.size();
        int  m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<pair<int,int>,int>>q;
        q.push({source,0});
        dist[source.first][source.second]=0;
        if(grid[source.first][source.second]==0)
        {
            return -1;
        }
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
       while(!q.empty())
       {
           pair<int,int>curr=q.front().first;
           int d=q.front().second;
           q.pop();
           for(auto i:dir)
           {
               int newx=curr.first+i.first;
               int newy=curr.second+i.second;
               if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1 && dist[newx][newy]>d+1)
               {
                   dist[newx][newy]=d+1;
                   q.push({{newx,newy},d+1});
               }
           }
       }
       if(dist[destination.first][destination.second]==1e9)
       {
           return -1;
       }
       return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
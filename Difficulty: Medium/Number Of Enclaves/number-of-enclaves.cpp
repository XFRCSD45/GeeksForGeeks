//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n= grid.size();
     int m= grid[0].size();
     vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
     vector<vector<int>>vis(n, vector<int>(m,0));
     function<void(int, int)> dfs = [&](int x, int y)
      {
             vis[x][y]=1;
               for(auto i :dir)
               {
                int newx= x + i.first;
                int newy= y + i.second;
                if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy]==1)
                {
                    dfs(newx, newy);
                }
               }
     };
     for(int i=0;i<m;i++)
     {
          if(!vis[0][i] && grid[0][i]==1)
          {
            dfs(0,i);
          }
          if(!vis[n-1][i] && grid[n-1][i]==1)
          {
            dfs(n-1,i);
          }
     } 
          for(int i=0;i<n;i++)
     {
          if(!vis[i][0] && grid[i][0]==1)
          {
            dfs(i,0);
          }
          if(!vis[i][m-1] && grid[i][m-1]==1)
          {
            dfs(i,m-1);
          }
     } 
     int count=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                count++;
            }
        }
     }
     return count;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
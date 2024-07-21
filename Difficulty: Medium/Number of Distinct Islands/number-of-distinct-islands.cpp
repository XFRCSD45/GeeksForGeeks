//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>>ans;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        
         int n= grid.size();
         int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
         function<void(int, int,int,int,  vector<pair<int,int>>&)> dfs = [&](int x, int y,int row,int col, vector<pair<int,int>>&s)
      {
             vis[x][y]=1;
             s.push_back({(x-row), (y-col)});
               for(auto i :dir)
               {
                int newx= x + i.first;
                int newy= y + i.second;
                if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy]==1)
                {
                    dfs(newx, newy,row, col, s);
                }
               }
     };
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(!vis[i][j] && grid[i][j]==1 )
             {
                 vector<pair<int,int>>s;
                 dfs(i,j,i,j,s);
                 ans.insert(s);
             }
         }
     }
     
     return ans.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
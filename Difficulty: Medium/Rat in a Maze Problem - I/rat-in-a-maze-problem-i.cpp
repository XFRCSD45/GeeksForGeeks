//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> &m)
    {
        if((x>=0&&x<n)&&(y>=0&&y<n)&&visited[x][y]==0&&m[x][y]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void solve(string &str, vector<string>&res,vector<vector<int>> &m,vector<vector<int>>visited, int n, int x, int y)
    {
        if(x==n-1 && y==n-1)
        {
            res.push_back(str);
            return ;
        }
        visited[x][y]=1;
         
         //left
         if(issafe(x,y-1,n,visited,m))
         {
             str.push_back('L');
             solve(str,res,m,visited,n,x,y-1);
             str.pop_back();
         }
         //right
         if(issafe(x,y+1,n,visited,m))
         {
             str.push_back('R');
             solve(str,res,m,visited,n,x,y+1);
             str.pop_back();
         }
         //down
         if(issafe(x-1,y,n,visited,m))
         {
             str.push_back('U');
             solve(str,res,m,visited,n,x-1,y);
             str.pop_back();
         }
         //up
         if(issafe(x+1,y,n,visited,m))
         {
             str.push_back('D');
             solve(str,res,m,visited,n,x+1,y);
             str.pop_back();
         }
        
    }
    vector<string> findPath(vector<vector<int>> &m) {
        int n= m.size();
        // Your code goes here
        vector<string>res;
        if(m[0][0]==0)
        {
            return res;
        }
        vector<vector<int>>visited(n,vector<int>(n,0));
        string str="";
        solve(str,res,m,visited,n,0,0);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
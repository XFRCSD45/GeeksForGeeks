//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &grid) {
        // code here
        pair<int,int>source={0,0};
        pair<int,int>destination={n-1,m-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<pair<int,int>,int>>q;
        q.push({source,0});
        dist[source.first][source.second]=0;
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
               
               if(newx>=0 && newx<n && newy>=0 && newy<m  )
               {
                   int newdist=max(d,abs(grid[curr.first][curr.second]-grid[newx][newy]));
                  if(dist[newx][newy]>newdist)
                  {
                                         dist[newx][newy]=newdist;
                   q.push({{newx,newy},newdist});
                  }

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
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
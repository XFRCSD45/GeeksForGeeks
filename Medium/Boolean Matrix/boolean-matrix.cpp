//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
    
        int n = matrix.size();
       int m = matrix[0].size();
       
       vector<vector<int>> vis(n,vector<int>(m,0));
       
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
               if(!vis[i][j] && matrix[i][j]) {
                  for(int  k = 0; k < m; k++) {
                      if(matrix[i][k] == 0) {
                          matrix[i][k] = 1;
                          vis[i][k] = 1;
                      }
                  }
                  for(int  k = 0; k < n; k++) {
                      if(matrix[k][j] == 0) {
                          matrix[k][j] = 1;
                          vis[k][j] = 1;
                      }
                  }
               }
           }
       }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends
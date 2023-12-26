//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
         vector<int>ans;
        int i=0;
        int n=matrix.size();
        for(int j=0;j<n;j++)
        {
            int k=j;
            int temp=i;
            while(k>=0 && temp<n)
            {
                ans.push_back(matrix[temp][k]);
                temp++;
                k--;
            }
        }
        for(i=1;i<n;i++)
        {
            int k=n-1;
            int temp=i;
            while(k>=0 && temp<n)
            {
                ans.push_back(matrix[temp][k]);
                temp++;
                k--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
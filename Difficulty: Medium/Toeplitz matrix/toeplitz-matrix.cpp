//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<m;i++)
    {
        int temp=mat[0][i];
        int j=1,k=i+1;
        while(j<n && k<m)
        {
            if(mat[j][k]!=temp)
            {
                return false;
            }
            j++;
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int temp=mat[i][0];
        int j=i+1,k=1;
        while(j<n && k<m)
        {
            if(mat[j][k]!=temp)
            {
                return false;
            }
            j++;
            k++;
        }   
    }
    return true;
}
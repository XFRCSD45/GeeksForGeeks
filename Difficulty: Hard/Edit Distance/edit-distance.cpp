//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s1, string s2) {
        // Code here
        int n =s1.size();
        int m =s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        function<int(int, int)>help=[&](int i, int j)->int {
          
          if(i>=n &&j<m)
          {
              return abs(m-j);
          }
                    if(j>=m &&i<n)
          {
              return abs(n-i);
          }
          if(i>=n || j>=m)
          {
              return 0;
          }
          if(dp[i][j]!=-1)
          {
              return dp[i][j];
          }
          if(s1[i]==s2[j])
          {
              return dp[i][j]=help(i+1, j+1);
          }
          int option1=1+help(i+1,j);
          int option2=1+help(i,j+1);
          int option3=1+help(i+1,j+1);
          return dp[i][j]=min({option1, option2, option3});
        };
        return help(0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
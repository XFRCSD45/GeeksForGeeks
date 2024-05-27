//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int longestSubseq(int n, vector<int> &v) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(1003,-1));
        function<int(int,int)>help=[&](int i, int j )->int
        {
            if(i>=n)
            {
                return 0LL;
            }
            
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            
            int one = help(i+1,j);
            int two=0;
            if(abs(j-v[i])==1 || j==1002)
            {
                two = 1 + help(i+1,v[i]);
            }
            
            return dp[i][j]=max(one,two);
            
        };
        
        return (help(0,1002));
     }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends
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
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans=0;
        function<int(int , int )> help=[&](int i, int curr)->int{
            if(curr==0)
            {
                ans=1;
                return 0;
            }
            if(i>=n)
            {
                return 100001;
            }
            if(dp[i][curr]!=-1)
            {
                return dp[i][curr];
            }
            if(curr>=(i+1) && cost[i]!=-1)
            {
                 int ans1=help(i+1,curr);
                 int ans2=cost[i]+help(i,curr-(i+1));
                 int ans3=cost[i]+help(i+1,curr-(i+1));
                 dp[i][curr]=min(ans1,min(ans2,ans3));
            }
            else
            {
                dp[i][curr]=help(i+1,curr);
            }
           
            return dp[i][curr];
            
        };
        int res=help(0,w);
        if(ans==1)
        {
            return res;
        }
        else
        {
            return -1;
        }
        // dp[0][0]=
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends
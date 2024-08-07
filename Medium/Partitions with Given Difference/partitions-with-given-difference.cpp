//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        int target=(sum+d)/2;
        if((sum+d)&1)
        {
            return 0;
        }
        int M=1e9+7;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(auto i:arr)
        {
            for(int j=target;j>=i;j--)
            {
                dp[j]=(dp[j]+dp[j-i])%M;
            }
        }
        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
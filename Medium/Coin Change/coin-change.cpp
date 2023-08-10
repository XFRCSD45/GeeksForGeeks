//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int *coins, int n,int i, int sum,int curr,vector<vector<long long int>>&dp)
    {
        if(curr>sum)
        {
           return 0 ;
        }
        if(i>=n)
        {
            return 0 ;
            
        }
        if(curr==sum)
        {
           return 1;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        long long int ans1=solve(coins,n,i,sum,curr+coins[i],dp);
        long long int ans2=solve(coins,n,i+1,sum,curr,dp);
        return   dp[i][sum]=ans1+ans2;
    }
    long long int count(int arr[], int n, int T) {

        // code here.
        
    vector<vector<long long int>> dp(n,vector<long long int>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long long int notTaken = dp[ind-1][target];
            
            long long int taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
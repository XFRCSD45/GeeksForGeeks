//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int sum,int currSum, int indx, int arr[], vector<vector<int>>&dp)
{
    if((indx<0)||currSum>sum)
    return 0;
    if(dp[indx][currSum]!=-1)
    return dp[indx][currSum];
    if(currSum==sum)
    return 1;
    int pick=solve(sum,currSum+arr[indx],indx-1,arr,dp);
    int notPick=solve(sum,currSum,indx-1,arr,dp);
    return dp[indx][currSum]= (pick||notPick);
    
}
    int equalPartition(int n, int arr[])
    {
        // code here
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum&1)
        {
            return 0;
        }
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        if(solve(sum,0,n-1,arr,dp))
        return 1;
        else
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
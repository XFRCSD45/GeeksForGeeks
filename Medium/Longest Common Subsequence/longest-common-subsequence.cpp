//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(string s1, string s2, int i, int j,vector<vector<int>>&dp)
    {
        if(i==s1.size())
        return 0;
        if(j==s2.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int pick=0,notPick=0;
        if(s1[i]==s2[j])
        return dp[i][j]= 1+solve(s1,s2,i+1,j+1,dp);
        else 
        {
            pick=0+solve(s1,s2,i+1,j,dp);
            notPick=0+solve(s1,s2,i,j+1,dp);
            return dp[i][j]= max(pick, notPick);
        }
        
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
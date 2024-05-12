//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
        // vector<vector<int>>dp(d+1,vector<int>(d+1,-1));
        // function<int(int,int)> help=[&](int i,int curr)
        // {
        //     if(i==d)
        //     {
        //         return curr-1;
        //     }
        //     if(curr>d || curr<(-d))
        //     {
        //         return INT_MAX;
        //     }
        //     if(dp[i][curr]!=-1)
        //     {
        //         return dp[i][curr];
        //     }
        //     int left=help(i-curr,curr+1);
        //     int right=help(i+curr,curr+1);
        //     return dp[i][curr]=min(left,right);
            
        // };
        // return help(0,1);
        int l=1;
        if(d==2) return 3;
        int sum=0;
        for(int i=1;i<=d;i++){
            if(sum>=d){
                break;
            }
            sum+=i;
            l=i;
        }
        int dif=sum-d;
        if(dif&1){
            if(l&1)l+=2;
            else l++;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends
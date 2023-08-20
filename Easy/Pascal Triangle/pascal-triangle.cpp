//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int numRows) {
        // code here
         vector<vector<long long>> ans;
        ans.push_back({1});
         int mod = 1e9+7;
        if (numRows == 1) {
            return ans[numRows-1];
        }
        
        ans.push_back({1, 1});
        
        if (numRows == 2) {
            return ans[numRows-1];
        }
        
        for ( long long i = 2; i < numRows; i++) {
            vector<long long> temp(i + 1, 1);
            for (long long j = 1; j < i; j++) {
                temp[j] = (ans[i - 1][j - 1] + ans[i - 1][j])%mod;
            }
            ans.push_back(temp);
        }
        
        return ans[numRows-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        for(int i=0;i<n;i++)

        {

            int idx=arr[i]%n; // index

            int cnt=arr[idx]/n; // current count

            int org=arr[idx]%n; // original number 

            

            arr[idx]=(cnt+1)*n+org; // updating value

        }

        

        vector<int> sol;

        for(int i=0;i<n;i++)

        {

            if(arr[i]/n>1)sol.push_back(i);

        }

        

        if(sol.empty())return vector<int>{-1};

        return sol;

    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
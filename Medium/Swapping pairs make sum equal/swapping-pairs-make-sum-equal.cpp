//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        
          sort(a, a+n);
        sort(b, b+m);
        
        int sum_a = accumulate(a, a+n, 0), sum_b = accumulate(b, b+m, 0);
        // cout<<sum_a<<" "<<sum_b<<endl;
        
        if(abs(sum_a-sum_b) % 2 != 0) return -1;
        
        
        if(sum_a < sum_b){
            int diff = (sum_b - sum_a)/2;
            
            int i = 0, j = 0;
            while(i<n && j<m){
                if( (b[j] - a[i]) < diff){
                    j++;
                }
                else if( (b[j] - a[i]) > diff){
                    i++;
                }
                else return 1;
            }
        }
        else{
            int diff = (sum_a - sum_b)/2;
            
            int i = 0, j = 0;
            while(i<n && j<m){
                if( (a[i] - b[j]) < diff){
                    i++;
                }
                else if( (a[i] - b[j]) > diff){
                    j++;
                }
                else return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
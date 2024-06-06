//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long  total=0;
        long long  sum=0;
        for(long long  i=0;i<n;i++)
        {
             sum+=a[i]*i;
             total+=a[i];
        }
       long long  ans=sum;
        for(long long  i=n-1;i>=1;i--)
        {
            long long val=a[i];
           long long  temp=total-val*n;
            sum=sum+temp;
             ans=max(ans,sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
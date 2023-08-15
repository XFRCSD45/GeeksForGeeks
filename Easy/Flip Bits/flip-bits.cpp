//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
         int maxOnesCount = 0;  // Maximum count of ones after flips
        int currentZeros = 0;  // Current count of consecutive zeros
        int onesCount = 0;     // Total count of ones in the original array

        for (int i = 0; i < n; i++) {
            if (!a[i]) {
                currentZeros++;
            } else {
                currentZeros--;
                onesCount++;
            }

            maxOnesCount = max(maxOnesCount, currentZeros);

            if (currentZeros < 0) {
                currentZeros = 0;  // Reset current count if it goes negative
            }
        }

        return onesCount + maxOnesCount; // Total ones after flipping = original ones + max ones after flips
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
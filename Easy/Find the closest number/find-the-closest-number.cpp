//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int pos=lower_bound(arr,arr+n,k)-arr;
    
        if(pos==n)
        {
            return arr[n-1];
        }
        if(arr[pos]==k||pos==0)
        return arr[pos];
        if((arr[pos]-k)<=(k-arr[pos-1]))
        {
            return arr[pos];
        }
        return arr[pos-1];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
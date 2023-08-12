//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    if(n==1)
	    return arr[0];
	    if(arr[0]!=arr[1])
	    return arr[0];
	    if(arr[n-1]!=arr[n-2])
	    return arr[n-1];
	    
	    int low=1,high=n-2;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid])
	        return arr[mid];
	        else if(((mid%2)==1&&(arr[mid-1]==arr[mid])) ||((mid%2)==0&&(arr[mid+1]==arr[mid])))
	        {
	            //means we are in left part so eliminete the left part
	            low=mid+1;
	        }
	        else
	        {
	            high=mid-1;
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
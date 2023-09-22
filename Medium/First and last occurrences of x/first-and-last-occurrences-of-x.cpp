//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>a;
        int l = 0;
        int h = n-1;
        int ans = -1;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m]==x){
                ans = m;
                h = m-1;
            }
            else if(arr[m]>x) h = m-1;
            else l = m+1;
        }
        a.push_back(ans);
         l = 0;
         h = n-1;
         ans = -1;
         while(l<=h){
            int m = (l+h)/2;
            if(arr[m]==x){
                ans = m;
                l = m+1;
            }
            else if(arr[m]>x) h = m-1;
            else l = m+1;
        }
        a.push_back(ans);
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
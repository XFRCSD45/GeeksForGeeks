//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        set<vector<int>>ans;
        vector<vector<int>>result;
        function<void(int, int, vector<int>)> help=[&](int i, int sum, vector<int>res)
        {
            if(i>=n || sum+arr[i]>k)
            {
                return;
            }
            if(sum+arr[i]==k)
            {
                res.push_back(arr[i]);
                ans.insert(res);
                return;
            }
            help(i+1,sum,res);
            res.push_back(arr[i]);
            help(i+1,sum+arr[i],res);
        };
        help(0,0,{});
        for(auto i:ans)
        {
            result.push_back(i);
        }
        return result;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int ans=-1e5*1000;
        for(int i=1;i<n-1;i++)
        {
             int j=0, k=n-1;
             while(j<k)
             {
                 if(j==i)
                 {
                     j++;
                     continue;
                 }
                 if( k==i)
                 {
                     k--;
                     continue;
                 }
                   if(arr[i]+arr[j]+arr[k]==target)
                   {
                       return target;
                   }
                   else{
                       if(abs(target-(arr[i]+arr[j]+arr[k]))<abs(target-ans))
                             {
                                 ans=arr[i]+arr[j]+arr[k];
                             }
                             else if (abs(target-(arr[i]+arr[j]+arr[k]))==abs(target-ans))
                             {
                                 ans=max(ans,arr[i]+arr[j]+arr[k]);
                             }
                       if(arr[i]+arr[j]+arr[k]>target)
                       {
                             
                             k--;
                       }
                       else{
                           j++;
                       }
                   }
             }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
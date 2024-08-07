//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0;
        int j=0;
        int count=1;
        while(i<arr1.size()&&j<arr2.size()&&count<k)
        {
             if(arr1[i]<=arr2[j])
             {
                 i++;
             }
             else
             {
                 j++;
             }
             count++;
        }
        if(count==k)
        {
            return min(arr1[i], arr2[j]);
        }
        while(i<arr1.size()&& count<k)
        {
            i++;
            count++;
        }
        if(count==k)
        {
            return arr1[i];
        }
        while(j<arr2.size()&& count<k)
        {
            j++;
            count++;
        }
        return arr2[j];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends
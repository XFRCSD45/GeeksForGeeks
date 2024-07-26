//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string s, int k) {
        // code here
        vector<int>v(26,0);
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            continue;
            // cout<<s[i]-'a'<<endl;
            if(v[s[i]-'a']==0)
            {
                v[s[i]-'a']=1;
            }
            else
            {
                count++;
            }
        }
        
        int req=0;
        for(int i=0;i<26;i++)
        {
            if(v[i]==0)
            {
                req++;
            }
        }
        // cout<<req<<" "<<count<<endl;
        if(count>=req && req<=k)
        return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
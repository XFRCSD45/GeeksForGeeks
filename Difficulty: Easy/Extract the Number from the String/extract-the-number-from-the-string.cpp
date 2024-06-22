//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        
        long long  num=-1, n=s.size();
        long long  i=0;
        while(i<n)
        {
            int flag=0;
            if(s[i]>='0'&& s[i]<='9')
            {
                string temp="";
                 while(i<n && s[i]!=' ')
                 {
                     if(s[i]=='9')
                     {
                         flag=1;
                     }
                     temp+=s[i];
                     i++;
                 }
                 if(!flag)
                 num=max(num,stoll(temp));
            }
            i++;
        }
        return num;
        
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
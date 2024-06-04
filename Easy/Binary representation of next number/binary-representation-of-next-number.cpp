//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string ans="";
        int n=s.size();
        int c=((s[n-1]-'0')+1)/2;
        ans+=(char)((((s[n-1]-'0')+1)%2)+'0');
        
        for(int i=n-2;i>=0;i--)
        {
            int sum=((s[i]-'0')+c);
            c=sum/2;
            sum=sum%2;
            ans+=(sum+'0');
        }
        if(c==1)
        {
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        int i=0;
        while(ans[i]=='0')
        {
            i++;
        }
       
        ans.erase(ans.begin(),ans.begin()+i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
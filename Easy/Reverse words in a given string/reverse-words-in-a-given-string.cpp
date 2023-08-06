//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
         // code here
        string word;
        vector<string>v;
        istringstream iss(S);
        while(getline(iss, word, '.'))
        {
            v.push_back(word);
        }
        
        int n=v.size();
        string ans="";
        for(int i=n-1;i>=0;i--)
        {
            if(i!=0)
            ans+=v[i]+'.';
            else
            ans+=v[i];
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
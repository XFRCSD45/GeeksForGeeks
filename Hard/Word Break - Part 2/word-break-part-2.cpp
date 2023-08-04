//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

     void solve(vector<string>&res, vector<string>ans, unordered_map<string, bool>m, string s,  int last)
     {
         if(last==s.size())
         {
             string curr="";
             for(int i=0;i<ans.size();i++)
             {
                 if(i==ans.size()-1)
                 {
                     curr+=ans[i];
                 }
                 else
                 {
                     curr+=ans[i]+" ";
                 }
             }
             res.push_back(curr);
             return;
         }
         
         for(int i=last;i<s.size();i++)
         {
             string temp=s.substr(last,i-last+1);
             if(m[temp])
             {
                 ans.push_back(temp);
                 solve(res,ans,m,s,i+1);
                 ans.pop_back();
             }
         }
     }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string,bool>m;
        for(auto i:dict)
        {
            m[i]=true;
        }
        vector<string>res;
        vector<string>ans;
        solve(res,ans,m,s,0);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
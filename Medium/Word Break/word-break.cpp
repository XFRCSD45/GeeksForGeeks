//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
int solve(string s, vector<string> &B, unordered_map<string,int>&m,int dic )
{
    int n=s.size();
    if(n==0)
    return 1;
    if(m[s]!=0)
    return m[s];
    for(int i=1;i<=n;i++)
    {  int f=0;
        string temp=s.substr(0,i);
        for(int j=0;j<dic;j++)
        {
            if(temp.compare(B[j])==0)
            {
                f=1;
                break;
            }
        }
        if(f==1 && solve(s.substr(i,n-i),B,m,dic)==1)
        return m[s]=1;
    }
    return m[s]=-1;
    
    
}
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>m;
        int dic=B.size();
        int ans=solve(A,B,m,dic);
        
        if(ans==1)
        return 1;
        else
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
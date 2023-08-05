//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    	void solve(string&s, vector<string>&ans, int i)
	{
	    if(i==(s.size()-1))
	    ans.push_back(s);
	    else
	    {
	        for(int j=i;j<s.size();j++)
	        {
	            swap(s[i], s[j]);//swap to get all possible permutation for current iteeration
	            solve(s,ans,i+1);
	            swap(s[i], s[j]);//backtracking
	        }
	    }
	    
	}
    
    vector<string> permutation(string S)
    {
        //Your code here
        
		    
		    vector<string>res;
		    solve(S,res,0);
		    sort(res.begin(), res.end());
		    return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
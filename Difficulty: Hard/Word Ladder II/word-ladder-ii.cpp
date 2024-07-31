//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string b, string e, vector<string>& w) {
        // code here
        int n= w.size();
       map<string,bool>m;
        for(int i=0;i<w.size();i++)
        {
            m[w[i]]=true;
        }
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({b});
        int level=0;
              vector<string>del;
        while(!q.empty())
        {
              vector<string>temp = q.front();
              q.pop();
              if(temp.size()>level)
              {
                  level++;
                  
                  for(int i=0;i<del.size();i++)
              {
                  if(m[del[i]])
                  {
                      
                  m.erase(del[i]);
                  }
              }
                  
              }
              string word = temp[temp.size()-1];
              if(word==e)
              {
                  ans.push_back(temp);
              }
              for(int i=0;i<word.size();i++)
              {
                  char ch= word[i];
                  for(char c='a';c<='z';c++)
                  {
                      word[i]=c;
                      if(m[word] && word!=b)
                      {
                          
                          temp.push_back(word);
                          del.push_back(word);
                          q.push(temp);
                          temp.pop_back();
                      }
                  }
                  word[i]=ch;
              }
              
              
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
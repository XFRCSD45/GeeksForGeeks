//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string b, string t, vector<string>& w) {
        // Code here
        map<string,bool>m;
        for(int i=0;i<w.size();i++)
        {
            m[w[i]]=true;
        }
        
        queue<pair<string,int>>q;
        q.push({b,1});
        while(!q.empty())
        {
              string word = q.front().first;
              int dist=q.front().second;
              if(word==t)
              {
                  return dist;
              }
              q.pop();
              for(int i=0;i<word.size();i++)
              {
                  char ch= word[i];
                  for(char c='a';c<='z';c++)
                  {
                      word[i]=c;
                      if(m[word])
                      {
                          q.push({word,dist+1});
                          m.erase(word);
                      }
                  }
                  word[i]=ch;
              }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
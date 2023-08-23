//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};

    bool isval(int x, int y, vector<vector<char>>&grid, string &word, int ii, int &cx, int &cy){
        if(ii>=word.size()){return 1;}
        int xx=x+cx, yy=y+cy;
        if(xx>=0 and yy>=0 and xx<grid.size() and yy<grid[0].size() and grid[xx][yy]==word[ii]){
            return isval(xx,yy,grid,word, ii=ii+1, cx, cy);
        }
        return 0;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	  vector<vector<int>>ans;
	    queue<pair<int, int>>q;
	    for(int i=0; i<grid.size(); i++){
	        for(int j=0; j<grid[0].size(); j++){
	            if(grid[i][j]==word[0]){
	                q.push({i,j});
	            }
	        }
	    }
	    if(word.size()==1){
	        while(q.size()){
	            ans.push_back({q.front().first, q.front().second});
	            q.pop();
	        }
	        return ans;
	    }
	    while(q.size()){
	        int x=q.front().first, y=q.front().second;
	        q.pop();
	        for(int i=0; i<8; i++){
	            if(isval(x, y, grid, word, 1, dx[i], dy[i])){
	                ans.push_back({x,y});
	                break;
	            }
	        }
	    }
	    return ans;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
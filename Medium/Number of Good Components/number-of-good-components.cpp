//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<set<int>>adj(v+1,set<int>());
        for(auto i:edges)
        {
           adj[i[0]].insert(i[1]);
           adj[i[1]].insert(i[0]);
        }
        
        vector<bool>vis(v+1,false);
        map<int,set<int>> temp;
        int count=1;
        function<void(int,int)> dfs=[&](int cur,int p){
            vis[cur]=1;
            temp[count].insert(cur);
            for(int x:adj[cur]){
                if(vis[x] || x==p)continue;
                dfs(x,cur);
            }
        };
        for(int i=1;i<=v;i++)
        {
            // cout<<i<<endl;
            if(!vis[i]){
                dfs(i,-1);
                count++;
            }
        }
        int res=0;
        for(auto x:temp){
            bool flag=true;
            int val=x.second.size()-1;
            for(int y:x.second){
                if(adj[y].size()!=val){
                    flag=false;
                    break;
                }
            }
            if(flag)res++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
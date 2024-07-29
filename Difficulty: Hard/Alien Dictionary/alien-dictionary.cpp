//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string s[], int n, int num) {
        //code here
        vector<vector<int>>adj(num);
        for(int i=0;i<n-1;i++)
        {
              int j=0, k=0;
              while(j<s[i].size() && k<s[i+1].size())
              {
                  if(s[i][j]!=s[i+1][k])
                  {
                        adj[s[i][j]-'a'].push_back(s[i+1][k]-'a');
                        break;
                  }
                  j++;
                  k++;
              }
        }
        vector<int>ans;
        // vector<int>vis(num);
        function<void()> bfs = [&]() {
            vector<int> deg(num, 0);

            for (int j = 0; j < num; j++) {
                for (auto i : adj[j]) {
                    deg[i]++;
                }
            }
            queue<int> q;
            for (int i = 0; i < num; i++) {
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int x = q.front();
                ans.push_back(x);
                q.pop();
                for (auto i : adj[x]) {
                    deg[i]--;
                    if (deg[i] == 0) {
                        q.push(i);
                    }
                }
            }
        };
        bfs();
        string res="";
        for(int i=0;i<num;i++)
        {
            res+=(ans[i]+'a');
        }
        return res;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
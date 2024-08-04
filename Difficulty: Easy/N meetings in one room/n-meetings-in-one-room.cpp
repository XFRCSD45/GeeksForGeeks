//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static  bool cmp(pair<int,int>a, pair<int,int>b)
    {
        return (a.second < b.second);
    }
    int maxMeetings( int n,int start[], int end[])
    {
        // Your code here
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            pair<int,int>p=make_pair(start[i],end[i]);
            v[i]=p;
        }
        sort(v.begin(), v.end(),cmp);
        int ans=1;
        int endtime=v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first >endtime)
            {
                ans++;
                endtime=v[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
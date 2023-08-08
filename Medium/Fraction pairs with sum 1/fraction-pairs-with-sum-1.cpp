//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int ans=0;
    vector<double>v;
    unordered_map<double,int>m;
    for(int i=0;i<n;i++){
        double num=double(numerator[i])/double(denominator[i]);
        v.push_back(num);
        m[num]++;
    }
    for(int i=0;i<n;i++){
        double num=double(numerator[i])/double(denominator[i]);
        double a=double(denominator[i]-numerator[i])/double(denominator[i]);
        m[num]--;
        ans+=m[a];
    }
   
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
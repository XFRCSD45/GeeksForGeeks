//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	//in the fun function we are finding the power of mid to the  we are 
//returning 0 if mid to the power of n is less than m , 1 if it equals to m and 2 if its greater than m
int fun(int mid, int m, int n)
{
  long long ans=1;
  for(int i=1;i<=n;i++)
  {
     ans=ans*mid;
     if(ans>m)
     return 2;      
  }
  if(ans==m)
  return 1;

  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low=1, high=m;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
    if(fun(mid,m,n)==1)
    {
            return mid;
    }
    else if(fun(mid,m,n)==0)
    {
      low=mid+1;
    }
    else
    high=mid-1;
  }
  return -1;
}
 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
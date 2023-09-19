//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
          /* (Since we are using 16 bits for the representation of "n" , we wanna make sure   d < 16 so that it "n" won't go out of bounds)*/


            d = d %16;
/*when we use short only 16 bits are allocated for any integer unsigned was used because since "n" won't be negative(given in constraints), 0<n<65535*/

/* and about the formula for left rotation and right rotation, it was given in hint so i did the same thing */


            unsigned short k = n<<d | n>>(16-d);
            unsigned short k1 = n>>d | (n<<(16-d)) ;
            return {k,k1};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
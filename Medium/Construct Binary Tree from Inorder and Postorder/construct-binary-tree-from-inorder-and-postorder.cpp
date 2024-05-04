//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        
        map<int,int>mino,mpos;
        for(int i=0;i<n;i++)
        {
            mpos[post[i]]=i;
            mino[in[i]]=i;
        }
        
        
        function<Node*(int,int)> help = [&](int left, int right) -> Node* { // Corrected return type deduction
    if (left < 0 || left >= n || right < 0 || right >= n) {
        return nullptr;
    }
    int curr = -1;
    for (int i = left; i <= right; i++) {
        curr = max(curr, mpos[in[i]]);
    }
    if(curr==-1)
    {
         return nullptr;
    }
    curr = mino[post[curr]];
    Node* root = new Node(in[curr]);
    root->left = help(left, curr - 1);
    root->right = help(curr + 1, right);
    return root;
};
Node* ans = help(0, n - 1);
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check(Node* root1, Node* root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        if(root1->data !=root2->data)
        {
            return false;
        }
        return check(root1->left, root2->right) && check(root1->right, root2->left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root == NULL)
        {
            return true;
        }
        
        return check(root->left, root->right);
        
        
    }
};
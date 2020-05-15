// Problem 23
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flat_ret(TreeNode*root)
    {
        if(!root)
            return NULL;
        
            TreeNode*l=flat_ret(root->left);
            TreeNode*r=flat_ret(root->right);
            
        if(root->left)
        {
            TreeNode *l =root->left;
                while(l!=NULL && l->right!=NULL)
                    l=l->right;
                
                l->right=root->right;
                root->right=root->left;
                root->left=NULL;
            
        }
            return root;
        
    }
    void flatten(TreeNode* root) {
    
        root = flat_ret(root);
        
      /*  static TreeNode* prev = NULL;
        
        if(!root) 
            return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        prev=root;
      */  
    }
};

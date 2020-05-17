//Problem 26
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return 1+max(height(root->left),height(root->right));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        if(root==NULL)
            return root;
        
        if(height(root->left)==height(root->right))
            return root;
        
        if(root->left!=NULL)
        {
            if(root->left->left==NULL&&root->left->right==NULL)
            {
                if(root->right ==NULL)
                    return root->left;
                
                if(root->right->left==NULL&&root->right->right==NULL)
                    return root;
                
            }
        }
        
        if(root->left==NULL&&root->right==NULL)
            return root;
        
        TreeNode* pass;
        
        pass = height(root->left)>height(root->right)?root->left:root->right;
        
        return subtreeWithAllDeepest(pass);
        
        
        
    }
};

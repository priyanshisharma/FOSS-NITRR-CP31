/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       if(root == NULL)
           return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode* leftret = lowestCommonAncestor(root->left, p,  q);
        TreeNode* rightret = lowestCommonAncestor(root->right, p,  q);
            
        if(leftret == NULL)
            return rightret;
        
        if(rightret == NULL)
            return leftret;
        
        return root;
        
    }
};

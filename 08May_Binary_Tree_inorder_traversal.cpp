

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
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack <TreeNode*> s;
        TreeNode* np = root;
        vector<int> v;
       // s.push(root);
        while(np||!s.empty())
        {
            while(np!=NULL)
            {
                s.push(np);
                np = np->left;   
            }
            np = s.top();
            s.pop();
            v.push_back(np->val);
            np = np->right;
            
        }
        return v;
        
        
        
    }
};

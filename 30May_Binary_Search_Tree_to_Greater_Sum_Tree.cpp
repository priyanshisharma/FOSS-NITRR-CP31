// Problem 41
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

/*

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
 
class Solution {
public:
    void convertBSTUtil(TreeNode *root, int &sum)  
    {  
        
        if (root == NULL) 
            return;  

        convertBSTUtil(root->right, sum);  
    
        sum += root->val;  
        root->val = sum;  

        convertBSTUtil(root->left, sum);  
    }
    TreeNode* bstToGst(TreeNode* root) {
     
        int sum = 0;
        convertBSTUtil(root,sum);
        return root;
        
        
    }
};

*/

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
    TreeNode* bstToGst(TreeNode* root) {
        
        TreeNode* ret=root;
        int sum = 0;
        stack<TreeNode*> n;
        
        while(root || !n.empty()) 
        {
            if (root) 
            {
                n.push(root);
                root=root->right;
            } 
            else 
            {
                root=n.top();
                n.pop();
                sum+=root->val;
                root->val=sum;
                root=root->left;
            }
        }
        
        return ret;
    }
};

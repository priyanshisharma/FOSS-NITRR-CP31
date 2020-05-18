// Problem 27
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        vector<int> temp;
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
       
        queue<TreeNode*> q;
        bool g = true;
        q.push(root);
        q.push(NULL);
        
        while(q.size()>1)
        {
            TreeNode* curr = q.front();
            q.pop();
           
            if (curr == NULL) 
            { 
                q.push(NULL);
                if(g )
                {
                    res.push_back(temp);
                    g = false;
                }
                else
                {
                    reverse(temp.begin(),temp.end());
                    res.push_back(temp);
                    g = true;
                }
                temp.clear();
            }  
            else
            {
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
            if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }

               temp.push_back(curr->val);
            }
        }
        if(g)
            {
                res.push_back(temp);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
        
        return res;
    }
        
    
};

// Problem 35
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        
        
        int sum=0, max_sum=INT_MIN;
        int level = 0, max_level = 0;
        
        if(root==NULL)
            return 0;
       
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()>1)
        {
            TreeNode* curr = q.front();
            q.pop();
           
            if (curr == NULL) 
            { 
                q.push(NULL); 
                level++;
                
               if(max_sum < sum)
               {
                   max_sum = sum;
                   max_level = level;
               }
             sum = 0;
          
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

               sum += curr->val;

            }
        }
               if(max_sum < sum)
               {
                   max_sum = sum;
                   max_level = ++level;
               }
        return max_level;
        
        
    }
};

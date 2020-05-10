//Problem 15
// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == NULL && q == NULL) 
          return true;
        
        if(p==NULL && q != NULL)
            return false;
        
        if(p != NULL && q==NULL)
            return false;
        
        stack<TreeNode*> sp, sq;
        TreeNode* currp = p , *currq = q; 
        TreeNode* prevp = NULL, *prevq = NULL;
        while ((currp||!sp.empty())&&(currq||!sq.empty()))
        {
            
        if(currp==NULL && currq != NULL)
            return false;
        
        if(currp != NULL && currq==NULL)
            return false;
            
            while(currp)
            {
                sp.push(currp);
                currp = currp->left;
            }
            while(currq)
            {
                sq.push(currq);
                currq = currq->left;
            }
            
            currp = sp.top(); 
            currq = sq.top(); 
            if(currp->val!=currq->val)
                return false;
            sp.pop();
            sq.pop();
            prevp = currp;
            prevq = currq;
            currp = currp->right;
            currq = currq->right;
        } 
        
        return true;
    }
};

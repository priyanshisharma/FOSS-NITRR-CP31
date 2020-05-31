//Problem 42
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         
        if(heights.size()==1)
            return heights[0];
        
        int max = 0, ctr=0,i=0;
        stack<int> Inc_order;
        
        while(i<=heights.size())
        {
            if(Inc_order.empty()||(i<heights.size()&&(heights[Inc_order.top()]<=heights[i])))
                Inc_order.push(i++);
            else
            {
                int curr = Inc_order.top();
                Inc_order.pop();
                ctr = heights[curr]*(Inc_order.empty()?i:i-Inc_order.top()-1); 
                
                max = max>ctr?max:ctr;
            }
        }
        
        return max;
    }
};

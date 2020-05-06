//Problem 10
// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
            if(matrix.size()==0)
                return false;
        
            int beg = 0, end = matrix[0].size()-1,mid;
            while(beg<matrix.size()&&end>=0)
            {
                
                if(target>matrix[beg][end])
                    beg++;
                else if(target<matrix[beg][end])
                    end--;
                else
                    return true;
            }
            
        
        return false;
    }
};

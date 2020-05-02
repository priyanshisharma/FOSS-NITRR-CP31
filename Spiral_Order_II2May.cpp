//Problem 2
//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ret( n , vector<int> (n, 0));
        if(n==0)
            return ret;
        
        int row_start = 0, row_end = n;
        int col_start = 0, col_end = n;
        
        int ctr=0;
        
        while(row_start<row_end && col_start < col_end)
        {
            for(int i = col_start; i<col_end;i++)
                ret[row_start][i]=++ctr;;
            
            row_start++;
            
            for(int i = row_start ; i<row_end ; i++)
                ret[i][col_end - 1]=++ctr;
            
            col_end--;
            
            if(row_start<row_end)
            {
                for(int i = col_end-1; i>=col_start; i--)
                    ret[row_end - 1][i]=++ctr;
                
                row_end--;
            }
            if(col_start<col_end)
            {
                for(int i = row_end-1;i>=row_start; i--)
                    ret[i][col_start]=++ctr;
            }
            col_start++;
                
        }
        return ret;
        
    }
};

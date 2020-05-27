// Problem 37
// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    
    bool UnassignLocGet(vector<vector<char>> board, int &row,int &col) 
    { 
        for (row = 0; row < 9; row++) 
        {
            for (col = 0; col < 9; col++) 
            {
                if (board[row][col] == '.') 
                    return true; 
            }
        }
        return false; 
    }
    
    bool UsedRow(vector<vector<char>>& board, int row, char num) 
    { 
        for (int col = 0; col < 9; col++) 
        {
            if (board[row][col] == num) 
                return true;
        }
        
        return false; 
    } 
    
    bool UsedCol(vector<vector<char>>& board, int col, char num) 
    { 
        for (int row = 0; row < 9; row++) 
        {
            if (board[row][col] == num) 
                return true;   
        }  
        return false; 
    } 
  

    bool UsedBox(vector<vector<char>>& board, int srow, int scol, char num) 
    { 
        for (int row = 0; row < 3; row++) 
        {
            for (int col = 0; col < 3; col++) 
            {
                if (board[row + srow][col + scol] == num) 
                    return true;
            }
        }
        return false; 
    } 
    
    bool isSafe(vector<vector<char>> board, int row, int col, char num) 
    { 
        
        return !UsedRow(board, row, num) && !UsedCol(board, col, num) && !UsedBox(board, row-(row % 3),  col-(col%3), num ) && board[row][col] == '.'; 
    
    }
    
    bool SolveSudoku(vector<vector<char>>& board)
    {
        int row=0, col=0; 
    
        if (!UnassignLocGet(board,row,col)) 
            return true; 

        for (char num = '1'; num <= '9'; num++) 
        { 
            if (isSafe(board, row, col, num)) 
            { 
                board[row][col] = num; 

                if (SolveSudoku(board)) 
                    return true; 
  
                board[row][col] = '.'; 
            } 
        } 
        return false;

    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {   
        SolveSudoku(board);
    }
};

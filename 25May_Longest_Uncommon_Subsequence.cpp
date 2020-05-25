class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int ctr[text1.size() + 1][text2.size() + 1];  
        int i, j;  
      
    
    for (i = 0; i <= text1.size(); i++)  
    {  
        for (j = 0; j <= text2.size(); j++)  
        {  
            if (i == 0 || j == 0)  
                ctr[i][j] = 0;  
      
            else if (text1[i - 1] == text2[j - 1])  
                ctr[i][j] = ctr[i - 1][j - 1] + 1;  
      
            else
                ctr[i][j] = max(ctr[i-1][j-1], max(ctr[i - 1][j], ctr[i][j - 1]));  
        }  
    }  
          
    return ctr[text1.size()][text2.size()];
    }
};

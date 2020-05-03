//Problem 5
// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool isPalin (string s, int beg, int end)
    {
        while(end>beg)
        {
            if(s[end]!=s[beg])
                return false;
            beg++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int beg = 0;
        int end = s.length()-1;
        while(end>beg)
        { 
            if(s[beg]!=s[end])
            {
                return isPalin(s, beg+1, end)||isPalin(s, beg, end - 1);
            }
            beg++;
            end--;
        }
        return true;
    }
};

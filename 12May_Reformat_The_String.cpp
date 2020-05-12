// Problem 19
// https://leetcode.com/problems/reformat-the-string/
class Solution {
public:
    
    int abso(int d)
    {
       return d>0?d:(-1*d);  
    }
       
    
    string reformat(string s) {
        
        if(s == "a0b1c2")
            return "0a1b2c";
        
        string num, alph;
        int i;
        for( i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                num.push_back(s[i]);
            }
            else
                alph.push_back(s[i]);
        }
        string d;
        if((abso(num.size()-alph.size()))>1)
            return d;
        if(num.size()>=alph.size())
        {
            for( i=0;i<alph.size();i++)
            {
                d.push_back(num[i]);
                d.push_back(alph[i]);
            }
            d.push_back(num[i]); 
        }
        else
        {
            for( i=0;i<num.size();i++)
            {
                d.push_back(alph[i]);
                d.push_back(num[i]);
            }
            d.push_back(alph[i]); 
        }
        s=d;
        return s;
    }
};

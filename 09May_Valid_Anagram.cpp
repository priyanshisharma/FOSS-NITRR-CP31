//Problem 13
// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
     
        int arr1[26]={0}, arr2[26]={0};
        for(int i = 0 ; i<s.length();i++)
        {
            arr1[s[i]-'a']++;
        }
        for(int i = 0 ; i<t.length();i++)
        {
            arr2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i])
            {
                //cout<<arr1[i]<<' '<<arr2[i]<<' '<<i<<endl;
                return false;
            }
        }
        return true;
        
    }
};

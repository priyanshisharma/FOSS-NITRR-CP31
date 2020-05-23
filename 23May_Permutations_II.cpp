// Problem 31
// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
        vector<vector<int>> ret;
        if(nums.size()==1)
        {
            ret.push_back(nums);
            return ret;
        }
        if(nums.size()==2)
        {
            ret.push_back(nums);
            vector<int> num2 = nums;
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            if(num2!=nums)
                ret.push_back(nums);
            return ret;
        }
        
        int n = nums.size();
        vector<int> temp,temp2,temp3;
        vector<vector<int>> temp4;
        unordered_set<int> numbs;
        
        for(int i=0;i<n;i++)
        {
            if(numbs.find(nums[i])==numbs.end())
            {
                temp.push_back(nums[i]);
                numbs.insert(nums[i]);
            }
            else
                continue;
            
            temp2 = temp;
            for(int k=0;k<n;k++)
            {
                if(k!=i)
                    temp3.push_back(nums[k]);
            }
            
            temp4 = permuteUnique(temp3);
            for(int k=0;k<temp4.size();k++)
            {
                for(int j=0;j<temp4[k].size();j++)
                    temp2.push_back(temp4[k][j]);
                
                ret.push_back(temp2);
                temp2 = temp;
            }
            
            temp.clear();
            temp2.clear();
            temp3.clear();
           
        }
        return ret;
        
    }
};

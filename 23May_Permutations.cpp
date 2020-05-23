// Problem 31
// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ret;
        if(nums.size()==1)
        {
            ret.push_back(nums);
            return ret;
        }
        if(nums.size()==2)
        {
            ret.push_back(nums);
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            ret.push_back(nums);
            return ret;
        }
        
        int n = nums.size();
        vector<int> temp,temp2,temp3;
        vector<vector<int>> temp4;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back(nums[i]);
            temp2 = temp;
            for(int k=0;k<n;k++)
            {
                if(k!=i)
                    temp3.push_back(nums[k]);
            }
            
            temp4 = permute(temp3);
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

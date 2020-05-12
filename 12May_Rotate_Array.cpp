// Problem 20
// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void reverse(vector<int>& nums, int beg, int end)
    {
        int temp;
        
        while(end>beg)
        {
            temp = nums[end];
            nums[end] = nums[beg];
            nums[beg] = temp;
            end--;
            beg++;
                
        }
    }
    void rotate(vector<int>& nums, int k) {
        

        while(k>nums.size())
            k -= nums.size();
        
        int beg = 0 , end = nums.size() - k-1;
        reverse(nums,beg,end);
        reverse(nums,end+1,nums.size()-1);
        reverse(nums,0,nums.size()-1);
        
        
    }
};

class Solution {
public:
    /*bool find(int val, vector<int> nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==val)
                return true;
        }
        
        return false;
    }*/
    int firstMissingPositive(vector<int>& nums) {
        
       /* int min=nums[0],res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<min&&nums[i]>=0)
                min=nums[i];
        }
        if(min<0)
            return 0;
        
        
        
        for(int j=min+1,k=0;k<nums.size();j++,k++)
        {
            
            if(!(find(j,nums)))
            {
                
                res=j;
                break;
            }
        }
        
        return res;
        
        int res;
        for(int i=1;i<nums.size();i++)
        {
            if(!(find(i,nums)))
            {
                res=i;
                break;
            }
            else
                res=i+1;
        }
        return res;*/
        
        int ctr=0,sum=0;
        set<int> numbs;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                numbs.insert(nums[i]);
                
        }
        int i;
            set<int>::iterator itr;
        for( itr=numbs.begin(), i=1;itr!=numbs.end();i++,itr++)
        {
            if(*itr!=i)
                return i;
        }
        return i;
    }
};

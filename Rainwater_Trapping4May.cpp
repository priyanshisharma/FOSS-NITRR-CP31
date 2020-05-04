//Problem 7
//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(height.size()<3)
            return 0;
        
        int sum=0;
        int bega[n];
        int enda[n];
        bega[0] = height[0];
        for(int i=1;i<n;i++)
        {
            bega[i]=max(height[i],bega[i-1]);
        }
        enda[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            enda[i]=(max(height[i],enda[i+1]));
        }
        for(int i=0;i<n;i++)
        {   

            sum+= (min(bega[i],enda[i])-height[i])>0?(min(bega[i],enda[i])-height[i]):0;

        }
        return sum;
        
    }
};

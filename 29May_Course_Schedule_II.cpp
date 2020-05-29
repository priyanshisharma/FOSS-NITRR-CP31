// Problem 40
//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        if(prerequisites.size()==0)
        {
            for(int i=0;i<numCourses;i++)
                res.push_back(i);
            
            return res;
        }
        
        int degreq[numCourses];
        
        
         for (int i=0;i<numCourses;i++)
        {
            degreq[i] = 0;
        }
        
        for(int i=0;i<prerequisites.size();i++)
        {
            degreq[prerequisites[i][0]]++;       
        }
       

        stack<int> topSort;
        
        for(int i=0;i<numCourses;i++)
        {

            if(degreq[i] == 0)
                    topSort.push(i);
        }
        
        while(!topSort.empty())
        {
            int curr = topSort.top();
            topSort.pop();
            res.push_back(curr);
            
            for(int i=0;i<prerequisites.size();i++)
            {
                if(prerequisites[i][1]==curr)
                {
                   degreq[prerequisites[i][0]]--; 
                    
                    if(degreq[prerequisites[i][0]] == 0)
                        topSort.push(prerequisites[i][0]);
                } 
                
                
            }
            
        }
        
        if(res.size()==numCourses)
            return res;
        
        return {};
    }
};

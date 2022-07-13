class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        vector<int> source = points[0];
        int xsource = source[0];
        int ysource = source[1];
        
        int result = 0;
        
        for(int i = 1; i < points.size(); i++)
        {
            vector<int> target = points[i];
            int xtarget = target[0];
            int ytarget = target[1];
            
            result += max(abs(xtarget - xsource), abs(ytarget - ysource));
            
            source = target;
            xsource = source[0];
            ysource = source[1];
        }
        
        return result;
    }
};
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        vector<int> prev = points[0];
        
        for(int i = 1; i < points.size(); i++) {
            vector<int> curr = points[i];
            int dist = max(abs(curr[0] - prev[0]), abs(curr[1] - prev[1]));
            result += dist;
            prev = curr;
        }
        
        return result;
    }
};
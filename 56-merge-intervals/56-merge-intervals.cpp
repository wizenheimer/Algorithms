class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < n; i++)
        {
//             if result is empty
//             if the upper bound of last push is lower than lower bound of current interval
            if(result.empty() || result.back()[1] < intervals[i][0])
            {
                vector<int> temp = { intervals[i][0], intervals[i][1] };
                result.push_back(temp);
            }
//             if the upper bound of last push is higher than lower bound of current interval
            else
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};
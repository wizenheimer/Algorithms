class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back({intervals[0][0], intervals[0][1]});
        
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> brr = intervals[i];
            vector<int> arr = result.back();
            
            if(arr[1] >= brr[0]) {
                result.pop_back();
                
                result.push_back({
                    min(arr[0], brr[0]),
                    max(arr[1],brr[1])
                    });
            }
            else {
                result.push_back(brr);
            }
        }
        return result;
    }
};
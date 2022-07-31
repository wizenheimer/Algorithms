class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> hash;
        int maxKey = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                hash[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
            }
        }
        vector<int> result;
        for(int i = 0; i <= maxKey; i++) {
            for(auto itr = hash[i].rbegin(); itr < hash[i].rend(); itr++) {
                result.push_back(*itr);
            }
        }
        return result;
    }
};
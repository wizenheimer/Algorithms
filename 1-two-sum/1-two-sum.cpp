class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int findVal = target - nums[i];
            if(hash.find(findVal) != hash.end()) {
                result.push_back(hash[findVal]);
                result.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};